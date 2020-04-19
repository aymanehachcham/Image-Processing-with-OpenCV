// OpenCV test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace  cv;
using  std::cout;
using  std::cin;
using std::endl;


int main()
{
	/*Mat image = Mat::zeros(300, 600, CV_8UC3);
	circle(image, Point(250, 150), 100, Scalar(0, 255, 128), -100);
	circle(image, Point(350, 150), 100, Scalar(255, 255, 255), -100);
	imshow("Display Window", image);
	waitKey(0);*/

	/*Mat img = imread("C:\\Users\\ayman\\OneDrive\\Pictures\\OPENCV-Images\\image1.jpg", IMREAD_GRAYSCALE);
	Mat img_resized;
	Size size(500, 350);
	resize(img, img_resized, size);

	Scalar img_intensity = img_resized.at<uchar>(35, 40);
	cout << img_intensity.val[0];

	if (img.empty())
		return -1;

	String windowName = "Image";
	namedWindow(windowName);

	imshow(windowName, img_resized);
	waitKey(0);

	destroyWindow(windowName);*/

	Mat first_image, new_image, image;
	double alpha = 5.0, beta = 20;

	first_image = imread("C:\\Users\\ayman\\OneDrive\\Pictures\\OPENCV-Images\\image1.jpg");
	Size size(500, 350);
	resize(first_image, image, size);

	new_image = Mat::zeros(image.size(), image.type());

	for (int y = 0; y < image.rows; y++)
		for (int x = 0; x < image.cols; x++)
			for (int c = 0; c < image.channels(); c++)
				new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);

	imshow("Original Image", image);
	imshow("Modified Image", new_image);
	waitKey(0);
 
	/*addWeighted(src1, alpha, src2, beta, 0.0, dest);
	Size size(500, 350);
	resize(dest, resized_dest, size);

	imshow("Destination", resized_dest);
	waitKey(0);*/

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
