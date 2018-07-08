void Operations::line(Image* img, int x0, int y0, int x1, int y1, Pen* pen) {
		int wsp[4] = {x0, y0, x1, y1};
		if(abs(y1-y0) <= abs(x1-x0)) { // X wiodaca osia (-a/b <= 1)
				if(x0<=x1) { // +X
						if(y0 <= y1) { // y++
								drawLine<0, 0, 1>(img, wsp, pen);
						} else { // y--
								drawLine<0, 0, -1>(img, wsp, pen);
						}
				} else { // -X
						if(y0 <= y1) {
								drawLine<0, 1, 1>(img, wsp, pen);
						} else {
								drawLine<0, 1, -1>(img, wsp, pen);
						}
				}
		} else { // Y wiodaca
				if(y0<=y1) { // +Y
						if(x0 <= x1) { // x++
								drawLine<1, 0, 1>(img, wsp, pen);
						} else { // x--
								drawLine<1, 0, -1>(img, wsp, pen);
						}
				} else { // -Y
						if(x0 <= x1) {
								drawLine<1, 1, 1>(img, wsp, pen);
						} else {
								drawLine<1, 1, -1>(img, wsp, pen);
						}
				}
		}
}

// tan (pochodna <= 1 lub nie) -> 0 (wiodacy X), 1 (wiodacy Y)
// lr - idzie w prawo czy w lewo wzgledem osi kierujacej -> +X/+Y -> 0, -X/-Y -> 1
// ud - w gore czy w dol wzgledem osi kierujacej // y++/x++ -> 1, y--/x-- -> -1
template<int tanx, int lr, int ud>
void Operations::drawLine(Image* temp, int* wsp, Pen* pen) {
	RGBColor p = *(pen->col);
	int a, b;
	(*temp)(wsp[0], wsp[1]) = p;


	int tan2 = (tanx==0) ? 1 : 0;
	int lr2 = (lr==0) ? 1 : 0;
	int sign = (lr==1) ? -1 : 1;

	int j = wsp[lr*2 + tan2];
	int k = wsp[lr2*2 + tanx];

	if(tanx) {
		a = -2*abs(wsp[2]-wsp[0]);
		b = 2*abs(wsp[3]-wsp[1]);
	} else {
		a = -2*abs(wsp[3]-wsp[1]);
		b = 2*abs(wsp[2]-wsp[0]);
	}

	int F_M1 = a + (b>>1);

	for(int i = wsp[lr*2+tanx]+1; i < k; i++)
	{
		 if(F_M1 <= 0)
		 {
			 j = j + sign*ud;
			 F_M1 += (a + b);
		 }
		 else
			 F_M1 += a;

		 if(tanx)
			 (*temp)(j, i) = p;
		 else
			 (*temp)(i, j) = p;
	 }
}

