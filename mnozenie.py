def TOOM1(wsp1, wsp2):
	size1 = len(wsp1)
	size2 = len(wsp2)
	newPoly = []
	for i in range(size1+size2-1):
		newPoly.append(0)

	for i in range(len(wsp1)):
		for j in range(len(wsp2)):
			newPoly[i+j] += (wsp1[i]*wsp2[j])

	return newPoly

def TOOM2A(wsp1, wsp2):
	# dlugosci wielomianow wejsciowych
	s1 = len(wsp1)
	s2 = len(wsp2)

	#jesli s1 i s2 sa rozne, to dopelniamy jeden z wielomianow zerami
	# az bedzie s1 == s2, czyli w przypadku s1 > s2, dodajemy (s1-s2) zer do wsp2 
	# w przeciwnym przypadku analogicznie
	if s1 > s2:
		for i in range(s1-s2):
			wsp2.append(0)
	elif s1 < s2:
		for i in range(s2-s1):
			wsp1.append(0)
	
	# potega dwojki
	# jesli s1 i s2 nie sa potegami dwojki, to dopelniamy je do pierwszej wiekszej niz s1 oraz s2 potegi dwojki
	k = 1
	while True:
		if len(wsp1) > k: # szukamy pierwszej wieksze potegi dwa od len(wsp1)
			k = k * 2
		elif len(wsp1) == k:
			break
		else:
			for i in range(k-len(wsp1)):
				wsp1.append(0)
				wsp2.append(0)
			break

	poly = TOOM2B(wsp1, wsp2)

	# tutaj ucinamy niepotrzebne zera na koncu
	newSize = len(poly)
	lp = len(poly)
	cutPoly = []
	for i in range(len(poly)):
		if poly[lp-1-i] == 0:
			newSize -= 1
		else:
			break

	for i in range(newSize):
		cutPoly.append(poly[i])		

	return cutPoly

def TOOM2B(wsp1, wsp2):
	siz = len(wsp1)
	if siz == 1:
		# jesli len(wsp1) == 1 (oraz len(wsp2) == 1, ale to wtedy oczywiste, bo wsp1 oraz wsp2 tej samej dlugosci)
		# to tworzymy jednoelementowy wielomian uzyskany z pomnozenia wyrazow wolnych i go zwracamy
		# jest to przypadek koncowy rekurencji, bez tego bylaby nieskonczona
		oneElement = []
		oneElement.append(wsp1[0]*wsp2[0])
		return oneElement
	else:
		# dzielimy rozmiar na 2
		siz2 = int(siz/2)
		wspA1, wspA2, wspB1, wspB2 = ([] for i in range(4))
		#splitting - dziele na k(2) czesci
		# i tworzymy dla obu wielomianow dwa mniejsze wielomiany zlozone z polowy tych wejsciowych
		# tutaj przepisujemy stary wielomian do dwoch mniejszych, nowych
		for i in range(siz2):
			wspA1.append(wsp1[i])
			wspA2.append(wsp1[siz2 + i]) # siz2 + i oznacza ze przepisywanie zaczynamy od poczatku drugiej polowy wielomianu
			wspB1.append(wsp2[i])
			wspB2.append(wsp2[siz2 + i])
		#evaluation
		#wielomiany wspA2*y + wspA1 oraz wspB2*y + wspB1
		# czyli musze ewaluowac w 3 punktach.. niech to beda -1, 0, 1
		# c = [a[i]+b[i] for i in range(len(a))]
		p = [[]  for i in range(3)]
		q = [[]  for i in range(3)]

		p[0] = wspA1 #0 po podstawieniu x = 0, mamy wspA2*0 + wspA1 = wspA1
		p[1] = [wspA2[i] + wspA1[i] for i in range(siz2)] #Dla x = 1 mamy wspA2*1 + wspA1 = wspA2 + wspA1
		p[2] = [wspA1[i] - wspA2[i] for i in range(siz2)] #-1 analogicznie

		# to samo co dla p
		q[0] = wspB1
		q[1] = [wspB2[i] + wspB1[i] for i in range(siz2)]
		q[2] = [wspB1[i] - wspB2[i] for i in range(siz2)] # 2 to -1

		# rekurencja
		for i in range(3):
			p[i] = TOOM2B(p[i], q[i]) # wywolujemy rekurencyjnie TOOM2B w celu policzenia wartosci r(i) = p(i)*q(i)	
			# jest to po to, aby uzyskac 3 punkty, ktore pomogą nam w interpolacji wyniku
			# to znaczy mnozac dwa wielomiany stopnia 1, czyli wspA2*y + wspA1 oraz wspB2*y + wspB1
			# uzyskamy jakis wielomian stopna 3, wiec mamy 3 wspolczynniki (czyli 3 niewiadome)
			# czyli potrzebujemy 3 punktow do interpolacji (u nas to byly 0, 1, -1) oraz r(i) to beda wartosci
			# w tych punktach dla mnozenia wielomianow, tzn r(x) = p(x)*q(x)

		#[[1, 0, 0], [0, 1/2, -1/2], [-1, 1/2, 1/2]]
		# tutaj jest trick z mnozeniem przez te macierz i robienie macierzy odwrotnej (ten trick pokazany na wikipedii, dzieki ktoremu nie musimy wyliczac tych rownan eliminacja gaussa albo czyms do niej podobnym)
		q[0] = p[0]		
		q[1] = [(p[1][i] - p[2][i])/2 for i in range(len(p[0]))]
		q[2] = [-p[0][i] + (p[1][i] + p[2][i])/2 for i in range(len(p[0]))]

		#wzorek
		#w1(x) * w2(x) = sum i=0 to 2k (r_i * x^{i*k^{c-1}}) k^c-1 to u nas siz2
		# przepisujemy wg wzoru pierwszy wielomian przesuwamy o x^0*siz2 = x^0, drugi o x^1*siz2 = x^siz2, trzeci o x^(2*siz2) 
		#czyli jesli chcemy stworzyc z 3 wielomianow o stopniu 2 nowy wielomian stopnia 7
		# to poczatkowo mamy tablice [0, 0, 0, 0, 0, 0, 0, 0] dla nowego wielomianu
		# i teraz powiedzmy, ze mamy te trzy male wielomiane uzyskane dla 0, 1, -1 i niech to będą 
		# niech siz2 = 2 dla uproszczenia przykladu
		# [1, 3, 4] , [2, -1, 1], [3, -2, 1]
		# czyli pierwszy to 4x^2 + 3x + 1 i skoro przesuwamy o x^0 to trafia na miejsca z indeksami 0, 1, 2
		# czyli [1, 3, 4, 0, 0, 0, 0, 0] dla duzego wielomianu
		# drugi wielomian przesuwamy o x^2 czyli dodajemy wspolczynniki do indexow duzej tablicy od 2 do 4
		# czyli [1, 3, 6, -1, 1, 0, 0, 0]
		# i trzeci na indeksach 4-6, czyli [1, 3, 6, -1, 4, -2, 1, 0] i to nasz wielomian, ktory zwracamy poprzez return wynik
		# uwaga - to nie musi byc nasz koncowy wynik (bo wywolujemy funkcje rekurencyjne, wiec tu moze byc wynik jakiegos rekurencyjnego wywolania)

		wynik = [0 for i in range(2*siz)]
		for i in range(3):
			for j in range(len(q[i])):
				wynik[i*siz2+j] = wynik[i*siz2+j] + q[i][j]
				#wynik.append(q[i][j])
		return wynik

def TOOM2(wsp1, wsp2):
	poly = TOOM2A(wsp1, wsp2)
	return poly

def TOOM3A(wsp1, wsp2):
	s1 = len(wsp1)
	s2 = len(wsp2)
	if s1 > s2:
		for i in range(s1-s2):
			wsp2.append(0)
	elif s1 < s2:
		for i in range(s2-s1):
			wsp1.append(0)
	
	k = 1
	while True:
		if len(wsp1) == k:
			break
		elif len(wsp1) > k:
			k = k * 3 # roznica taka ze tutaj chcemy miec potegi liczby 3 jak dlugosc tablic, czyli 3^c, gdzie c to jakas liczba naturalna
		else:
			for i in range(k-len(wsp1)):
				wsp1.append(0)
				wsp2.append(0)

	poly = TOOM3B(wsp1, wsp2)
	newSize = len(poly)
	lp = len(poly)

	cutPoly = []
	for i in range(len(poly)):
		if poly[lp-1-i] == 0:
			newSize -= 1
		else:
			break

	for i in range(newSize):
		cutPoly.append(poly[i])		

	return cutPoly

def TOOM3B(wsp1, wsp2):
	siz = len(wsp1)
	if siz == 1:
		oneElement = []
		oneElement.append(wsp1[0]*wsp2[0])
		return oneElement
	else:
		siz2 = int(siz/3)
		wspA1, wspA2, wspA3, wspB1, wspB2, wspB3 = ([] for i in range(6))
		#splitting - dziele na 3 czesci
		for i in range(siz2):
			wspA1.append(wsp1[i])
			wspA2.append(wsp1[siz2 + i])
			wspA3.append(wsp1[2*siz2 + i])
			wspB1.append(wsp2[i])
			wspB2.append(wsp2[siz2 + i])
			wspB3.append(wsp2[2*siz2 + i])

		#evaluation
		#wielomiany wspA3*y^2 + wspA2*y + wspA1 oraz wspB3*y^2 + wspB2*y + wspB1
		# czyli musze ewaluowac w 5 punktach.. niech to beda 0, 1, -1, -2, nieskoncznosc (odsylam na wikipedie - tam to jest opisane)
		# w naszej tablicy index 0 odpowiada punktowi 0, index 1 to 1, index 2 to -1, index 3 to -2, index 4 to nieskoncznonsc
		p = [[]  for i in range(5)]
		q = [[]  for i in range(5)]

		# wzory z wikipedii, anaalogiczne do toom2
		p[0] = wspA1 #0
		p[1] = [wspA3[i] + wspA2[i] + wspA1[i] for i in range(siz2)] #1
		p[2] = [wspA1[i] - wspA2[i] + wspA3[i] for i in range(siz2)] #-1
		p[3] = [wspA1[i] - 2*wspA2[i] + 4*wspA3[i] for i in range(siz2)]
		p[4] = wspA3

		q[0] = wspB1
		q[1] = [wspB3[i] + wspB2[i] + wspB1[i] for i in range(siz2)]
		q[2] = [wspB1[i] - wspB2[i] + wspB3[i] for i in range(siz2)]
		q[3] = [wspB1[i] - 2*wspB2[i] + 4*wspB3[i] for i in range(siz2)]
		q[4] = wspB3
		# rekurencja
		for i in range(5):
			p[i] = TOOM3B(p[i], q[i])

		#interpolacja, tak samo znowu analogicznie do toom2, a macierz odwrotna wzialem z wikipedii
		q[0] = p[0]		
		q[1] = [(p[0][i]/2 + p[1][i]/3 - p[2][i] + p[3][i]/6 - 2*p[4][i]) for i in range(len(p[0]))]
		q[2] = [(-p[0][i] + p[1][i]/2 + p[2][i]/2 - p[4][i]) for i in range(len(p[0]))]
		q[3] = [(-p[0][i]/2 + p[1][i]/6 + p[2][i]/2 - p[3][i]/6 + 2*p[4][i]) for i in range(len(p[0]))]
		q[4] = p[4]
		#wzorek
		wynik = [0 for i in range(3*siz)]
		for i in range(5):
			for j in range(len(q[i])):
				wynik[i*siz2+j] += q[i][j]

		wynik = [round(wynik[i]) for i in range(len(wynik))]
		return wynik

def TOOM3(wsp1, wsp2):
	poly = TOOM3A(wsp1, wsp2)
	return poly


w1 = [7, 8, 2] # x^4 + 3x^3 + 4x^2 + 4x + 11
w2 = [8, 6, 4, 2] # x^3 + 2x^2 + 3x + 4
w3 = TOOM1(w1, w2)
w4 = TOOM2(w1, w2)
w4 = [int(w4[i]) for i in range(len(w4))]
w5 = TOOM3(w1, w2)
w5 = [int(round(w5[i])) for i in range(len(w5))]
print(w3)
print(w4)
print(w5)
