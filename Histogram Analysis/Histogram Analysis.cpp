// Histogram Analysis.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/plot.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace  cv;
using std::cout;
using std::cin;
using std::vector;
using std::endl;
using cv::plot::Plot2d;
using cv::Ptr;

int main()
{
	// read the input image:
	/*Mat actual_image = imread("C:\\Users\\ayman\\OneDrive\\Pictures\\OPENCV-Images\\image1.jpg", IMREAD_COLOR), input_image;
	Size size(600, 512);
	resize(actual_image, input_image, size);

	// Separate the color image in three color channels:
	vector<Mat> bg_planes;
	split(input_image, bg_planes);

	// Configuring the histogram plot:
	int hist_size = 256;
	float range[] {0, 256 }; // upper float array boundary is exclusive
	const float* hist_range = { range };

	// We want our histogram bins to be uniform and non accumulated:
	bool uniform = true, accumulate = false;

	// We proceed t calculate the histograms for each bg_plane, RGB:
	Mat output_b, output_g, output_r;
	calcHist(&bg_planes[0], 1, 0, Mat(), output_b, 1, &hist_size, &hist_range, uniform, accumulate);
	calcHist(&bg_planes[1], 1, 0, Mat(), output_g, 1, &hist_size, &hist_range, uniform, accumulate);
	calcHist(&bg_planes[2], 1, 0, Mat(), output_r, 1, &hist_size, &hist_range, uniform, accumulate);

	// Create the window to display the histogram:
	int hist_width = 512, hist_height = 600;
	int bin_width = round((double)hist_width / hist_size);
	
	Mat histogram_image(hist_width, hist_height, CV_8UC3, Scalar(0, 0, 0));

	// Before displaying the histogram, we should normalize the values so the fall in the range of the parameters entered:
	normalize(output_b, output_b, 0, hist_size, NORM_MINMAX, -1, Mat());
	normalize(output_g, output_g, 0, hist_size, NORM_MINMAX, -1, Mat());
	normalize(output_r, output_r, 0, hist_size, NORM_MINMAX, -1, Mat());

	// Drawing the lines for each calculated output:
	for (int i = 1; i < hist_size; i++)
	{
		line(histogram_image, Point( bin_width*(i-1), hist_height - output_b.at<float>(i-1) ), 
			Point( bin_width*i, hist_height - output_b.at<float>(i)), Scalar(255, 0, 0), 2, 8, 0);

		line(histogram_image, Point(bin_width * (i - 1), hist_height - output_g.at<float>(i - 1)),
			Point(bin_width * i, hist_height - output_g.at<float>(i)), Scalar(0, 255, 0), 2, 8, 0);

		line(histogram_image, Point(bin_width * (i - 1), hist_height - output_r.at<float>(i - 1)),
			Point(bin_width * i, hist_height - output_r.at<float>(i)), Scalar(0, 0, 255), 2, 8, 0);
	}

	imshow("Source image", input_image);
	imshow("calcHist Demo", histogram_image);
	waitKey();*/

	Mat data_x(1, 51, CV_64F);
	Mat data_y(1, 51, CV_64F);

	for (int i = 0; i < data_x.cols; i++)
	{
		double x = (i - data_x.cols / 2);
		data_x.at<double>(0, i) = x;
		data_y.at<double>(0, i) = x * x * x;
	}

	std::cout << "data_x : " << data_x << std::endl;
	std::cout << "data_y : " << data_y << std::endl;

	Mat plot_result;

	Ptr<Plot2d> plot = Plot2d::create(data_x, data_y);
	plot->render(plot_result);

	imshow("The plot rendered with default visualization options", plot_result);

	plot->setShowText(false);
	plot->setShowGrid(false);
	plot->setPlotBackgroundColor(Scalar(255, 200, 200));
	plot->setPlotLineColor(Scalar(255, 0, 0));
	plot->setPlotLineWidth(2);
	plot->setInvertOrientation(true);
	plot->render(plot_result);

	imshow("The plot rendered with some of custom visualization options", plot_result);
	waitKey();
	
	return 0;
	


}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
