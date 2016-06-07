#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <zbar.h>


using namespace std;
using namespace zbar;



int main(int argc, char* argv[])  {  
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

	char buf[64];
	while ( scanf("%s", buf) ){  
		cv::Mat frame, grey;

		if ( frame.type() == CV_8UC1 ){
			cv::cvtColor(frame,grey,CV_BGR2GRAY);  
		} else {
			grey = frame;
		}

		int width  = frame.cols;
		int height = frame.rows;

		uchar *raw = (uchar *) grey.data;
		Image image(width, height, "Y800", raw, width * height);   
		int n = scanner.scan(image);
		for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol){
			/*vector<cv::Point> vp;
			//cout << "decoded " << symbol->get_type_name() << " symbol \"" << symbol->get_data() << '"' <<" "<< endl;   
			int n = symbol->get_location_size();   
			for(int i=0;i<n;i++){   
				vp.push_back(cv::Point(symbol->get_location_x(i),symbol->get_location_y(i)));   
			}
			cv::RotatedRect r = minAreaRect(vp);
			cv::Point2f pts[4];
			r.points(pts);
			for(int i=0;i<4;i++){
				line(frame,pts[i],pts[(i+1)%4],cv::Scalar(255,0,0),3);
			}*/
		}

		/*cv::imshow("MyVideo", frame);
		if (cv::waitKey(30) == 27){  
			cout << "esc key is pressed by user" << endl;
			break;
		}*/

	}
	return 0;
} 
