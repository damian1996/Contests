std::vector<std::complex<float>> Operations::rowsRecursiveFFT1D(zespo input, int N) {
	int Nprim = N/2;
	if(N==1) return input;
	cmpDabl omegaN = std::exp(cmpDabl(0.0, 1.0*(-2*M_PI)/N));
	cmpDabl omega(1.0, 0.0);
	zespo in0, in1;
	in0.resize(Nprim);
	in1.resize(Nprim);

	for(int i=0; i<N; i++) {
		i%2==0 ? in0[i/2] = input[i] : in1[i/2] = input[i];
	}
	in0 = rowsRecursiveFFT1D(in0, Nprim);
	in1 = rowsRecursiveFFT1D(in1, Nprim);
	for(int i=0; i<Nprim; i++) {
		input[i] = in0[i] + omega*in1[i];
		input[i+Nprim] = in0[i] - omega*in1[i];
		omega = omega*omegaN;
	}
	return input;
}

std::vector<std::complex<float>> Operations::rowsRevRecursiveFFT1D(zespo input, int N) {
	int Nprim = N/2;
	if(N==1) return input;
	cmpDabl omegaN = std::exp(cmpDabl(0.0, 1.0*(2*M_PI)/N));
	cmpDabl omega(1.0, 0.0);
	zespo in0, in1;
	in0.resize(N);
	in1.resize(N);

	for(int i=0; i<N; i++) {
		i%2==0 ? in0[i/2] = input[i] : in1[i/2] = input[i];
	}
	in0 = rowsRevRecursiveFFT1D(in0, Nprim);
	in1 = rowsRevRecursiveFFT1D(in1, Nprim);
	for(int i=0; i<Nprim; i++) {
		input[i] = in0[i] + omega*in1[i];
		input[i+Nprim] = in0[i] - omega*in1[i];
		omega = omega*omegaN;
	}
	return input;
}


void Operations::fft(const std::string& in, const std::string& out) {
		int N = (*images[in]).width();
		images[out] = new Image(N, N);

		zespo input[N];
		for(int i=0; i<N; i++) {
				input[i].resize(N);
				for(int j=0; j<N; j++)
						input[i][j] = cmpDabl((*images[in])(i, j).r, 0);
				input[i] = rowsRecursiveFFT1D(input[i], N);
		}
		for(int i=0; i<N; i++) {
				zespo output;
				output.resize(N);
				for(int j=0; j<N; j++)
						output[j] = input[j][i];

				output = rowsRecursiveFFT1D(output, N);
				for(int j=0; j<N; j++) {
						RGBColor& outPixel = (*images[out])(j, i);
						outPixel.r = std::real(output[j])/N;
						outPixel.g = std::imag(output[j])/N;
						outPixel.b = 0.0f/N;
				}
		}
}

void Operations::ifft(const std::string& in, const std::string& out) {
		int N = (*images[in]).width();
		images[out] = new Image(N, N);

		zespo input[N];
		for(int i=0; i<N; i++) {
				input[i].resize(N);
				for(int j=0; j<N; j++)
						input[i][j] = cmpDabl((*images[in])(i, j).r, (*images[in])(i, j).g);
				input[i] = rowsRevRecursiveFFT1D(input[i], N);
		}
		for(int i=0; i<N; i++) {
				zespo output;
				output.resize(N);
				for(int j=0; j<N; j++)
						output[j] = input[j][i];

				output = rowsRevRecursiveFFT1D(output, N);
				for(int j=0; j<N; j++) {
						RGBColor& outPixel = (*images[out])(j, i);
						float val = std::real(output[j])/N;
						outPixel.r = val;
						outPixel.g = val;
						outPixel.b = val;
				}
		}
}

