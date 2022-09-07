/* 
Mô tả: Bài toán thực hiện giải thuật tham lam chọn xe phù hợp để chở được tất cả các học sinh
Lưu ý: Mỗi xe có thêm 1 giáo viên trông lớp và 1 tài xế lái xe
*/
//Thư viện:
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <fstream> 
#include <iostream> 
#include <string>
#include <Windows.h>
#define MAX 100
using namespace std;

struct XeKhach
{
	char ten[50]; //tên hãng xe
	int soChoNgoi; // số ghế
	int giaThue; // giá của hãng xe
	float donGia; // giá 1 ghế ngồi
};

//----------------------------------------------------
//Khai báo hàm:
void menu();
void chayMenu();
void duongVien();
void set_font_color(int color); //đổi màu chữ
void docFile(XeKhach dsXe[], int &n, int &w);
void xuatFile(XeKhach dsXe[], int n, int w);
void sapXep(XeKhach dsVat[], int n);
void thucHienBaiToanChonXeChoHocSinh(XeKhach dsVat[], int n, int w, XeKhach dsChon[], int ndsChon[], int &nSoLuong); //hàm thực hiện giải thuật tham lam
void xuatXe(XeKhach dsChon[],int ndsChon[],int nSoLuong); // xuất danh sách đã xe được chọn
void xuatTongChoNgoi(XeKhach dsChon[],int ndsChon[],int nSoLuong); // xuất tổng số ghế
void xuatFiletxtXeDaThue (XeKhach dsChon[], int n); // in file txt danh sách xe đã thuê
void xuatTongChiPhiThueXe(XeKhach dsChon[],int ndsChon[],int nSoLuong);// xuất tổng chi phi thuê xe
void xuatTongChoNgoiKhongCoNguoiNgoi(XeKhach dsChon[],int ndsChon[],int nSoLuong, int a); // xuất số ghế không có người ngồi
void xuatTongChoNgoiCoNguoiNgoi(XeKhach dsChon[],int ndsChon[],int nSoLuong, int a); // xuất số ghế có người ngồi
void xuatTongChoNgoiTaiXeGiaoVien(XeKhach dsChon[],int ndsChon[],int nSoLuong); //xuất số ghế mà tài xế và giáo viên ngồi
void xuatFiletxtHoaDon (XeKhach dsChon[],int ndsChon[], int n);// xuất tổng hóa đơn thuê xe

//-------------------------------------------------------
//hàm main//

void main()
{
	chayMenu();
	_getch();
}

void menu()
{
	set_font_color(2);
	printf("\t***** CHUONG TRINH THUE XE CHO HOC SINH THUAT TOAN THAM LAM *****\n");
	printf("\t** 1. Hien thi danh sach hang xe co the thue                   **\n");
	printf("\t** 2. Thuc hien chon xe phu hop theo so luong hoc sinh         **\n");
	printf("\t** 3. Xem thong tin cho ngoi                                   **\n");
	printf("\t** 4. Xem tong chi phi bo ra de thue xe                        **\n");
	printf("\t** 5. In danh sach xe da thue ra file                          **\n");
	printf("\t** 6. In hoa don thue xe ra file                               **\n");
	printf("\t**");
	set_font_color(4);
	printf("	   He Thong: Nhap 0 de thoat khoi chuong trinh!        ");
	set_font_color(2);
	printf("**\n");
	printf("\t*****************************************************************\n");
}

void duongVien()
{
	set_font_color(6);
	printf("\n\n*******************************************************************************************************");
}

void chayMenu()
{
	int chon = 0;
	int m,n,w;
	
	XeKhach dsXe[MAX];
	XeKhach dsChon[MAX];
	int nChon[MAX]= {0};
	int nsoluong;
	docFile(dsXe,n,w);
	do
	{
	printf("\n\n");
	menu();
	duongVien();
	printf("\nNhap tuy chon theo chuc nang: ");
	scanf_s("%d",&chon);
	set_font_color(7);
	switch (chon)
	{

	case 1:
		set_font_color(4);
		printf("\n1. Hien thi danh sach hang xe co the thue \n");
		set_font_color(7);
		printf("\nDanh sach xe co the thue: \n");
		xuatFile(dsXe,n,w);
		duongVien();
		break;
	case 2:
		set_font_color(4);
		printf("\n2. Thuc hien chon xe phu hop theo so luong hoc sinh \n");
		printf("\n\tThong bao: He thong sap xep hang xe theo gia thue de tien hanh chon xe!\n");
		sapXep(dsXe,n);
		set_font_color(7);
		printf("\nDanh sach hang xe sau khi duoc sap xep lai :\n");
		xuatFile(dsXe,n,w);
		/*set_font_color(9);
		printf("\n\nNhap tong so hoc sinh de tien hanh chon xe: ");
		scanf_s("%d",&w);*/
		set_font_color(7);
		thucHienBaiToanChonXeChoHocSinh(dsXe,n,w,dsChon,nChon,nsoluong);	
		set_font_color(4);
		printf("\n\nKet qua chon duoc danh sach thue xe nhu sau: ");
		set_font_color(7);
		xuatXe(dsXe,nChon,nsoluong);
		duongVien();
		break;
	case 3:
		set_font_color(4);
		printf("\n3. Xem thong tin cho ngoi \n");
		set_font_color(9);
		xuatTongChoNgoi(dsXe,nChon,nsoluong);
		xuatTongChoNgoiTaiXeGiaoVien(dsXe,nChon,nsoluong);
		xuatTongChoNgoiKhongCoNguoiNgoi(dsXe,nChon,nsoluong,w);
		xuatTongChoNgoiCoNguoiNgoi(dsXe,nChon,nsoluong,w);
		duongVien();
		break;
	case 4:
		set_font_color(4);
		printf("\n4. Xem tong chi phi bo ra de thue xe \n");
		set_font_color(9);
		xuatTongChiPhiThueXe(dsXe,nChon,nsoluong);
		duongVien();
		break;
	case 5:
		set_font_color(4);
		printf("\n5. In danh sach xe da thue ra file \n");
		xuatFiletxtXeDaThue(dsXe,nsoluong);
		duongVien();
		break;
	case 6:
		set_font_color(4);
		printf("\n6. In hoa don thue xe ra file \n");
		xuatFiletxtHoaDon(dsXe,nChon,nsoluong);
		duongVien();
		break;
	}
	}while (chon!=0);
	
}

//Các hàm chính của bài tập

//hàm đổi màu chữ
void set_font_color(int color)
{
	 WORD wColor;
     
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}

//hàm đọc dữ liệu từ file
void docFile(XeKhach dsLoaiXe[] , int &n, int &w)
{
	char* filename = "../Data/ip.txt";
	ifstream in;
	in.open(filename);
	if (in)
	{
		in >> w;
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> dsLoaiXe[i].ten;
			in >> dsLoaiXe[i].soChoNgoi;
			in >> dsLoaiXe[i].giaThue;
			dsLoaiXe[i].soChoNgoi -= 2;
			dsLoaiXe[i].donGia = (float)dsLoaiXe[i].giaThue / dsLoaiXe[i].soChoNgoi;
		}
	}
	in.close();
}

//hàm xuất dũ liệu đọc được từ file
void xuatFile(XeKhach dsXe[], int n, int w)
{
	printf("\nLoaiXe\t\tSoCho\t\tGiaThue\t\tDonGia1ChoNgoi");
	for(int i=0;i<n;i++)
	{
		printf("\n");
		printf("%s\t",dsXe[i].ten);
		printf("\t%d",dsXe[i].soChoNgoi+2);
		printf("\t\t%d",dsXe[i].giaThue);
		printf("\t\t%.2f",dsXe[i].donGia);
	}

	printf("\n\n\tTong so hoc sinh: %d",w);
}

//hàm sắp xếp để thực hiện giải thuật tham lam
void sapXep(XeKhach dsVat[], int n)
{
	XeKhach tmp;
	for(int i = 0; i < n-1; i++)
		for(int j=i+1 ; j<n ; j++)
		{
			if(dsVat[j].donGia < dsVat[i].donGia)
			{
				tmp = dsVat[i];
				dsVat[i] = dsVat[j];
				dsVat[j] = tmp;
			}
		}
}

//hàm thực hiện giải thuật tham lam
void thucHienBaiToanChonXeChoHocSinh(XeKhach dsVat[], int n, int w, XeKhach dsChon[], int ndsChon[], int &nSoLuong)
{
	bool flag = false;
	if(w == 0) //nếu không có học sinh nào thì return
	{
		printf("\nKhong thue xe!\n");
		return;
	}
	nSoLuong = 0;
	int tam;
	for(int i = 0 ; i < n ; i++)
	{
		if(w <= 0) //sắp xe cho tất cả học sinh thì dừng
			return;

		tam = w/dsVat[i].soChoNgoi;

		while (w >= dsVat[i].soChoNgoi) //số học sinh còn lớn hơn hoặc số ghế của xe thì còn chọn thêm xe đó
		{
			dsChon[nSoLuong] = dsVat[i];
			ndsChon[nSoLuong]++;
			w -= dsVat[i].soChoNgoi;
			flag = true;
		}
		if(flag == true)
		{
			nSoLuong++;
			flag = false;
		}
		while(w > 0) //nếu số học sinh nhỏ hơn số ghế của xe và còn học sinh thì chọn được xe cuối cùng
		{
			int XeCuoiCung;
			float giaxetam = 0;
			float giaMin = dsVat[0].giaThue / dsVat[0].soChoNgoi;
					
			for(int j = 0 ; j < n ; j++)
			{
				giaxetam = dsVat[j].giaThue/w;
				if(giaxetam > giaMin)
				{
					dsChon[nSoLuong] = dsVat[j];
					XeCuoiCung = j;
				}
			}


			flag = false;
			for(int j = 0 ; j < nSoLuong ; j++)
			{
				if(strcmpi(dsVat[XeCuoiCung].ten , dsChon[j].ten) == 0) //kiểm tra xe cuối cùng đã có chưa
				{
					ndsChon[j]++;
					w-=dsVat[XeCuoiCung].soChoNgoi;
					flag = true;
				}
			}

			if(flag == false)
			{
				dsChon[nSoLuong] = dsVat[XeCuoiCung];
				ndsChon[nSoLuong]++;
				nSoLuong++;
				w-=dsVat[XeCuoiCung].soChoNgoi;
			}
		}
	}
}

//hàm xuất kết quả danh sách xe đã được thuê
void xuatXe(XeKhach dsChon[],int ndsChon[],int nSoLuong)
{
	int tongSoChoNgoi = 0;
	int tongSoChoiNgoiAll = 0;
	printf("\n");
	for(int i = 0; i < nSoLuong; i++)
	{
		printf("\n");
		printf("Xe %s", dsChon[i].ten);
		printf(" thue %d xe", ndsChon[i]);
	}
	
}

//hàm xuất tổng số ghế của tất cả các xe
void xuatTongChoNgoi(XeKhach dsChon[],int ndsChon[],int nSoLuong)
{
	int tongSoChoNgoi = 0;
	printf("\n");
	for(int i = 0; i < nSoLuong; i++)
	{
		tongSoChoNgoi += (dsChon[i].soChoNgoi + 2) * ndsChon[i];
	}
	printf("Tong so ghe tat ca cac xe la: %d",tongSoChoNgoi);
}

//hàm xuất tổng số ghế có người 
void xuatTongChoNgoiCoNguoiNgoi(XeKhach dsChon[],int ndsChon[],int nSoLuong, int a)
{
	int kq = 0;
	int tongChoNgoiTaiXeGiaoVien = 0;
	int tongSoChoNgoi = 0;
	int tongSoChoNgoiCoNguoiNgoi = 0;
	printf("\n");
	for(int i = 0; i < nSoLuong; i++)
	{
		tongSoChoNgoi += (dsChon[i].soChoNgoi + 2) * ndsChon[i];
		tongSoChoNgoiCoNguoiNgoi += (dsChon[i].soChoNgoi) * ndsChon[i];
	}
	tongChoNgoiTaiXeGiaoVien = tongSoChoNgoi - tongSoChoNgoiCoNguoiNgoi;
	kq = a + tongChoNgoiTaiXeGiaoVien;
	printf("Tong so ghe co nguoi ngoi la: %d",kq);
}

//hàm xuất tổng số ghế trống
void xuatTongChoNgoiKhongCoNguoiNgoi(XeKhach dsChon[],int ndsChon[],int nSoLuong, int a)
{
	int kq = 0;
	int tongChoNgoiTaiXeGiaoVien = 0;
	int tongSoChoNgoi = 0;
	int tongSoChoNgoiCoNguoiNgoi = 0;
	printf("\n");
	for(int i = 0; i < nSoLuong; i++)
	{
		tongSoChoNgoi += (dsChon[i].soChoNgoi + 2) * ndsChon[i];
		tongSoChoNgoiCoNguoiNgoi += (dsChon[i].soChoNgoi) * ndsChon[i];
	}
	tongChoNgoiTaiXeGiaoVien = tongSoChoNgoi - tongSoChoNgoiCoNguoiNgoi;
	kq = tongSoChoNgoi - ( a + tongChoNgoiTaiXeGiaoVien);
	printf("Tong so ghe khong co nguoi ngoi la: %d",kq);
}

//hàm xuất số ghế của tài xế và giáo viên
void xuatTongChoNgoiTaiXeGiaoVien(XeKhach dsChon[],int ndsChon[],int nSoLuong)
{
	int tongChoNgoiTaiXeGiaoVien = 0;
	int tongSoChoNgoi = 0;
	int tongSoChoNgoiCoNguoiNgoi = 0;
	printf("\n");
	for(int i = 0; i < nSoLuong; i++)
	{
		tongSoChoNgoi += (dsChon[i].soChoNgoi + 2) * ndsChon[i];
		tongSoChoNgoiCoNguoiNgoi += (dsChon[i].soChoNgoi) * ndsChon[i];
	}
	tongChoNgoiTaiXeGiaoVien = tongSoChoNgoi - tongSoChoNgoiCoNguoiNgoi;
	printf("Tong so ghe cua tai xe va giao vien la: %d",tongChoNgoiTaiXeGiaoVien);
}

//hàm xuất tổng chi phí thuê xe
void xuatTongChiPhiThueXe(XeKhach dsChon[],int ndsChon[],int nSoLuong)
{
	int tongChiPhi = 0;
	for(int i = 0; i < nSoLuong; i++)
	{
		tongChiPhi += dsChon[i].giaThue * ndsChon[i];
	}
	printf("\n\tTong chi phi thue xe la: %d",tongChiPhi);
}

//hàm in ra file danh sách xe đã thuê
void xuatFiletxtXeDaThue (XeKhach dsChon[], int n)
{
	set_font_color(4);
	char* filename = "../Data/danhsachxedathue.txt";
	ofstream out;
	out.open(filename);
	out << "STT\tTen\tSoChoNgoi\tGiaThue\tGia1Ghe";
	if (out)
	{
		for(int i=0;i<n;i++)
		{
			out << "\n";
			out << i+1 << "\t";
			out << " " << dsChon[i].ten << "\t";
			out << " " << dsChon[i].soChoNgoi + 2 << "\t\t";
			out << " " << dsChon[i].giaThue << "\t";
			out << " " << dsChon[i].donGia << "\t\t";
		}
	}
	out.close();
	duongVien();
	printf("\n\n-------------------IN FILE DANH SACH XE DA THUE THANH CONG--------------------\n");
}

//hàm in ra file tổng tiền hóa đơn thuê xe
void xuatFiletxtHoaDon (XeKhach dsChon[],int ndsChon[], int n)
{
	set_font_color(4);
	int tongChiPhi = 0;
	for(int i = 0; i < n; i++)
	{
		tongChiPhi += dsChon[i].giaThue * ndsChon[i];
	}
	char* filename = "../Data/hoadon.txt";
	ofstream out;
	out.open(filename);
	out << "STT\tTen\tSoChoNgoi\tGiaThue\tGia1Ghe";
	if (out)
	{
		for(int i=0;i<n;i++)
		{
			out << "\n";
			out << i+1 << "\t";
			out << " " << dsChon[i].ten << "\t";
			out << " " << dsChon[i].soChoNgoi + 2 << "\t\t";
			out << " " << dsChon[i].giaThue << "\t";
			out << " " << dsChon[i].donGia << "\t\t";
		}
	}
	out << "\n";
	out << "Tong hoa don: " << tongChiPhi << " VND";
	out.close();
	duongVien();
	printf("\n\n-------------------IN FILE HOA DON THANH CONG--------------------\n");
}