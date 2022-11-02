#include <iostream>
using namespace std;

struct student
{
  string hoTen;
  float dtb, toan, van;
};

void tinhDTB(student &hs)
{
  hs.dtb = (hs.toan + hs.van) / 2;
}

void xepLoai(student hs)
{
  if (hs.dtb >= 8)
  {
    cout << "Loai gioi.";
  }
  else if ((hs.dtb >= 7) && (hs.dtb < 8))
  {
    cout << "Loai kha.";
  }
  else if ((hs.dtb >= 5) && (hs.dtb < 7))
  {
    cout << "Loai trung binh.";
  }
  if (hs.dtb < 5)
  {
    cout << "Loai yeu.";
  }
}

istream &operator>>(istream &in, student &hs)
{
  cout << "Nhap ho va ten cua hoc sinh: ";
  fflush(stdin);
  getline(cin, hs.hoTen);
  cout << "Nhap diem mon Toan: ";
  in >> hs.toan;
  cout << "Nhap diem mon Van: ";
  in >> hs.van;
  tinhDTB(hs);
  return in;
}

ostream &operator<<(ostream &out, student &hs)
{
  out << "\nThong tin hoc sinh: \n"
      << "Ho va ten: " << hs.hoTen << " - Toan: " << hs.toan << " - Van: " << hs.van << " - Diem trung binh: " << hs.dtb;
  xepLoai(hs);
  return out;
}

int main()
{
  int n;

  cout << "Nhap so luong sinh vien: ";
  cin >> n;

  student stu[n + 1];

  for (int i = 0; i < n; i++)
  {
    cin >> stu[i];
  }

  for (int i = 0; i < n; i++)
  {
    cout << stu[i];
  }
  return 0;
}
