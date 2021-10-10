#include<iostream>
#include<opencv2/opencv.hpp>



using namespace std;
using namespace cv;
//12.05.2021 tarihinde 3. sýnýf mühendislik tasarýmý için tamamladýgým maske tespit yazýlýmý
//Emre Maltaþ
void maskeSon()
{

	//EMRE MALTAÞ

	string wName = "SON PENCERE";
	CascadeClassifier yuz;
	CascadeClassifier yuz2;

	CascadeClassifier burun;
	CascadeClassifier agiz;
	int maskesiz=0;
	yuz.load("haarcascade_frontalface_default.xml");
	yuz2.load("haarcascade_frontalface_default.xml");
	burun.load("haarcascade_mcs_nose.xml");
	agiz.load("haarcascade_mcs_mouth.xml");

	VideoCapture vCap;
	vCap.open(0);
	if (vCap.isOpened())
	{
		Mat ekran;
		Mat griEkran;
		Mat donusum;
		Mat donSon;

		while (true)
		{

			vector<vector<Point>>yuzKordinat;
			vector<vector<Point>>yuzAffine;
			vector<Rect>burunBul;
			vector<Rect>agizBul;
			vector<Mat>affineSonuc;
			vector<Rect>yuzBul;
			vector<Rect>yuzBul2;

			vCap.read(ekran);
			cvtColor(ekran, griEkran, COLOR_BGR2GRAY);

			yuz.detectMultiScale(griEkran, yuzBul, 1.1, 3, 0);


			if (yuzBul.size() >= 1)
			{
				for (int i = 0; i < yuzBul.size(); i++)
				{
					Point2f pt1[4] = { Point(yuzBul[i].x, yuzBul[i].y), Point(yuzBul[i].x + yuzBul[i].width, yuzBul[i].y),
						Point(yuzBul[i].x, yuzBul[i].y + yuzBul[i].height),Point(yuzBul[i].x + yuzBul[i].width, yuzBul[i].y + yuzBul[i].height) };

					Point2f pt2[4] = { Point(0,0),Point(yuzBul[i].width,0),Point(0,yuzBul[i].height),Point(yuzBul[i].width,yuzBul[i].height) };
					donusum = getAffineTransform(pt1, pt2);
					warpAffine(ekran, donSon, donusum, Size(0 + yuzBul[i].width, 0 + yuzBul[i].height), BORDER_CONSTANT, BORDER_TRANSPARENT);
					affineSonuc.push_back(donSon);


				}

				cvtColor(affineSonuc[0], affineSonuc[0], COLOR_BGR2GRAY);
				equalizeHist(affineSonuc[0], affineSonuc[0]);

				yuz2.detectMultiScale(affineSonuc[0], yuzBul2, 1.1, 3, 0, Size(5, 5), Size(150, 150));
				burun.detectMultiScale(affineSonuc[0], burunBul, 1.1, 3, 0, Size(5, 5), Size(35, 35));
				agiz.detectMultiScale(affineSonuc[0], agizBul, 1.1, 3, 0, Size(5, 5), Size(35, 35));

				//rectangle(affineSonuc[0], yuzBul2[0], Scalar(255, 0, 0), 2, 8);

				if (yuzBul2.size() >= 1)
				{
					rectangle(affineSonuc[0], yuzBul2[0], Scalar(255, 0, 0), 1, 8);
					if (agizBul.size() >= 1)
					{

						rectangle(affineSonuc[0], agizBul[0], Scalar(255, 0, 0), 1, 8);
					}
					if (burunBul.size() >= 1)
					{
						rectangle(affineSonuc[0], burunBul[0], Scalar(255, 0, 0), 1, 8);
					}

					if (agizBul.size() >= 1 || burunBul.size() >= 1)
					{
						putText(ekran, "Maske Takili Degil!!", Point(yuzBul[0].x, yuzBul[0].y),
							FONT_HERSHEY_TRIPLEX || FONT_ITALIC, 2, Scalar(0, 0, 255), 3, 8);
						imwrite("C:\\Users\\User\\Desktop\\maskesiz girenler\\maskesiz" + to_string(maskesiz) + ".jpg", ekran);
					}
					else
					{
						putText(ekran, "Maske Takili!!", Point(yuzBul[0].x, yuzBul[0].y),
							FONT_HERSHEY_TRIPLEX || FONT_ITALIC, 2, Scalar(0, 255, 0), 3, 8);
					}
				}

				
				imshow("donSon", affineSonuc[0]);
				maskesiz++;
			}
			else
			{
				cout << "Yuz tespit edilemedi!!" << endl;

			}

			imshow(wName, ekran);
			if (waitKey(100) == 27)break;
		}
	}


}

int main()
{
	maskeSon();
}