void Operations::convolveimg(std::string& out, const std::string& in, const std::string& k) {
		Image *localImg = images[in];
		RGBColor img;
		int imgWidth = localImg->width(), imgHeight = localImg->height();
		Kernel* localKernel = kernels[k];
		int kerW = localKernel->width(), kerH = localKernel->height();
		create(out, imgWidth, imgHeight);
		for(int x = 0; x<imgWidth; x++){
				for(int y = 0; y<imgHeight; y++) {
						RGBColor outImg;
	 					for(int p=0; p<kerW; p++) {
								for(int q=0; q<kerH; q++) {
										int xp=clamp(x+p-(kerW-1)/2, imgWidth), yq=clamp(y+q-(kerH-1)/2, imgHeight);
										img = (*localImg)(xp, yq);
										float kpq = localKernel->tab[q][p];
										outImg.r += (kpq*img.r);
										outImg.g += (kpq*img.g);
										outImg.b += (kpq*img.b);
								}
						}
						(*images[out])(x, y) = RGBColor(outImg.r, outImg.g, outImg.b);
				}
		}
}
