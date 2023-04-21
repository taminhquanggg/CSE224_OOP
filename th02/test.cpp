#include<iostream>
#include<stdio.h>

using namespace std;

//===chuong trinh chinh===
int main()
{
    // Khai bao bien
    int d, m, y, DayMax, DayOfWeek; // DayMax la so ngay toi da cho thang

    // Nhap du lieu
    cout<<"Nhap vao ngay: "; cin>>d;
    cout<<"Nhap vao thang: "; cin>>m;
    cout<<"Nhap vao nam: "; cin>>y;

    // Phan tich thiet ke giai thuat
    if(y<1582)
    {
        cout<<"Nam khong duoc xac dinh!";
        goto KetThuc;
    }

    if(m<1 || m>12)
    {
        cout<<"Thang khong hop le!";
        goto KetThuc;
    }

    switch(m)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            DayMax=30;
            break;
        case 2:
            DayMax=28+((y%4==0 && y%100!=0) || y%400==0);
            break;
        default:
            DayMax=31;
    }

    if(d<1 || d>DayMax)
    {
        cout<<"Ngay khong hop le!";
        goto KetThuc;
    }

    cout<<"Ngay - thang - nam deu hop le!";

    // Cong thuc Zeller
    y -= (14-m)/12;
    m += 12*((14-m)/12)-2;
    DayMax = (d + y + y/4 - y/100 + y/400 + (31*m)/12)%7;



    cout<<"\nThu "<<DayMax;


KetThuc:
    cout<<endl;
    return 0;
}
