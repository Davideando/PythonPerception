/*
*		Face Detector
*			Program to detect faces
*			By David Ortiz Martínez
*
*/

// OpenCV Libraries
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//std../../
#include <iostream>
#include <cstdlib>


int main(int argc, char *argv[]) 
{
	//OpenCV video capture object
    cv::VideoCapture capture;
	
	//OpenCV image object
    cv::Mat image;
	
	//camera id . Associated to device number in /dev/videoX
	int cam_id; 

	// Variable to store the face clasifier
	cv::CascadeClassifier face_detect;

	// Variable to store the detected faces
	std::vector<cv::Rect> faces;

	//check user args
	switch(argc)
	{
		case 1: //no argument provided, so try /dev/video0
			cam_id = 0;  
			break; 
		case 2: //an argument is provided. Get it and set cam_id
			cam_id = atoi(argv[1]);
			break; 
		default: 
			std::cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl; 
			std::cout << "EXIT program." << std::endl; 
			break; 
	}
	
	//advertising to the user 
	std::cout << "Opening video file " << cam_id << std::endl;

	// Loading the video
	capture = cv::VideoCapture("video.mpeg");

	// Verify if the video is opened
	if(!capture.isOpened())                              // Check for invalid video
    {
        std::cout <<  "Could not open or find the video" << std::endl;
        return -1;
    }

    // Load the XML file to detect faces
    if(!face_detect.load("haarcascade_frontalface_default.xml"))
    {
    	std::cout <<  "Could not open of find the XML file" << std::endl;
    	return -1;
    }

    // Program Loop
    while(1)
    {
	    // Se pasa la imagen al Mat
	  	capture.read(image);

	  	// Verify if the video is finished
	  	if(!image.data)
	  	{
	  		std::cout << "The video is finished!! Bye" << std::endl;
	  		break;
	  	}

	    cv::namedWindow( "Face Detector", cv::WINDOW_AUTOSIZE );// Create a window for display.
	    cv::imshow( "Face Detector", image );                   // Show our image inside it.

	    cv::waitKey(1);
	}

	// Destroy all windows
	cv::destroyWindow("Face Detector");

	// The end of the program
	return 0; 
}
