#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct khachHang
{
    char maKH[8];
    char hoTen[30];
    char gioiTinh[3];
    int namSinh;
    char soCMND[11];
    char queQuan[20];
    char ngayThue[10];
    khachHang *next;
};

struct phong
{
    char maPhong[3];
    int soGiuong;
    bool tinhTrang;
    khachHang *dsKH;
    phong *next;
};

struct nhanVien
{
    char maNV[8];
    char hoTen[30];
    char gioiTinh[3];
    int namsinh;
    char chucVu[10];
    double luong;
    nhanVien *next;
};

struct dichVu
{
    char tenDV[50];
    double gia;
    bool trangThai;
    dichVu *next;
};

void Menu();
void MenuKhachHang();
void MenuPhong();
void MenuNhanVien();
void MenuDichVu();
void MenuGhiDuLieu();
void themTTKH(khachHang *&dsKhachHang);
void nhapTTKH(khachHang *&dsKhachHang);
void inDanhSachKhachHang(khachHang *dsKhachHang);
bool kiemTraMaKhachHang(khachHang *dsKhachHang, char *maKH);
void xoaTTKH(khachHang *&dsKhachHang, char *maKH);
void suaTTKH(khachHang *dsKhachHang, char *maKH);
void thayTheTTKH(khachHang *&dsKhachHang, char *maKH);
void timKiemTTKHTheoMa(khachHang *dsKhachHang, char *maKH);
void inDanhSachPhong(phong *dsPhong);
void DKThuePhong(phong *dsPhong, char *maPhong, khachHang *dsKhachHang);
void DKTraPhong(phong *dsPhong, char *maPhong, khachHang *dsKhachHang);
void hienTTPhongDaThue(phong *dsPhong);
void hienTTPhongConTrong(phong *dsPhong);
void themTTNV(nhanVien *&dsNhanVien);
void nhapTTNV(nhanVien *&dsNhanVien);
bool kiemTraMaNhanVien(nhanVien *dsNhanVien, char *maNV);
void timKiemTTNVTheoMa(nhanVien *dsNhanVien, char *maNV);
void inDanhSachNhanVien(nhanVien *dsNhanVien);
void hienTTKHDaDangKyDichVu(phong *dsPhong, khachHang *dsKhachHang);
void khoiTaoDichVu(dichVu *&dsDichVu);
void inDanhSachDichVu(dichVu *dsDichVu);
void ghiDuLieuKH(khachHang *dsKhachHang, const string &data_KH);
void ghiDuLieuPhong(phong *dsPhong, const string &data_Phong);
void ghiDuLieuNhanVien(nhanVien *dsNhanVien, const string &data_NhanVien);
void ghiDuLieuDichVu(phong *dsPhong, khachHang *dsKhachHang, dichVu *dsDichVu, const string &data_DichVu);
phong *taoDanhSachPhong()
{
    phong *dsPhong = nullptr;
    for (int i = 1; i <= 20; ++i)
    {
        phong *phongMoi = new phong;
        sprintf(phongMoi->maPhong, "%03d", i);
        phongMoi->soGiuong = rand() % 2 + 1;
        phongMoi->tinhTrang = false;
        phongMoi->next = dsPhong;
        dsPhong = phongMoi;
    }
    return dsPhong;
}

int main()
{
    int chon;
    khachHang *dsKhachHang = nullptr;
    phong *dsPhong = taoDanhSachPhong();
    nhanVien *dsNhanVien = nullptr;
    dichVu *dsDichVu = nullptr;
    do
    {
        Menu();
        cout << "\nMoi ban chon 1 chuc nang: ";
        cin >> chon;
        switch (chon)
        {
        case 0:
            cout << "\nCam on ban da su dung chuc nang.";
            break;
        case 1:
            int choice;
            do
            {
                MenuKhachHang();
                cout << "\nMoi ban chon 1 chuc nang: ";
                cin >> choice;
                switch (choice)
                {
                case 0:
                    cout << "\nCam on ban da su dung chuc nang.";
                    break;
                case 1:
                    themTTKH(dsKhachHang);
                    inDanhSachKhachHang(dsKhachHang);
                    break;
                case 2:
                    char xoaMa[8];
                    cout << "\nNhap ma khach hang can xoa: ";
                    cin >> xoaMa;
                    xoaTTKH(dsKhachHang, xoaMa);
                    inDanhSachKhachHang(dsKhachHang);
                    break;
                case 3:
                    char suaMa[8];
                    cout << "\nNhap ma khach hang can sua: ";
                    cin >> suaMa;
                    suaTTKH(dsKhachHang, suaMa);
                    inDanhSachKhachHang(dsKhachHang);
                    break;
                case 4:
                    char thayMa[8];
                    cout << "\nNhap ma khach hang can thay: ";
                    cin >> thayMa;
                    thayTheTTKH(dsKhachHang, thayMa);
                    inDanhSachKhachHang(dsKhachHang);
                    break;
                case 5:
                    char ma[8];
                    cout << "\nNhap ma khach hang can tim: ";
                    cin >> ma;
                    timKiemTTKHTheoMa(dsKhachHang, ma);
                    break;

                default:
                    cout << "\nChuc nang nay khong ton tai:((";
                    break;
                }
            } while (choice != 0);
            break;
        case 2:
            int choice_1;
            do
            {
                cout << "\nDanh sach cac phong cua khach san: " << endl;
                inDanhSachPhong(dsPhong);
                cout << "\n";
                MenuPhong();
                cout << "\nMoi ban chon 1 chuc nang: ";
                cin >> choice_1;
                switch (choice_1)
                {
                case 0:
                    cout << "\nCam on ban da su dung chuc nang.";
                    break;
                case 1:
                    char maP[3];
                    cout << "\nNhap ma phong can dang ky: ";
                    cin >> maP;
                    DKThuePhong(dsPhong, maP, dsKhachHang);
                    break;
                case 2:
                    char maPg[3];
                    cout << "\nNhap ma phong can tra: ";
                    cin >> maPg;
                    DKTraPhong(dsPhong, maPg, dsKhachHang);
                    break;
                case 3:
                    cout << "\nDanh sach cac phong da duoc khach hang thue: " << endl;
                    hienTTPhongDaThue(dsPhong);
                    break;
                case 4:
                    cout << "\nDanh sach cac phong con trong: " << endl;
                    hienTTPhongConTrong(dsPhong);
                    break;

                default:
                    cout << "\nChuc nang nay khong ton tai:((";
                    break;
                }
            } while (choice_1 != 0);

            break;
        case 3:
            int choice_2;
            do
            {
                MenuNhanVien();
                cout << "\nMoi ban chon 1 chuc nang: ";
                cin >> choice_2;
                switch (choice_2)
                {
                case 0:
                    cout << "\nCam on ban da su dung chuc nang.";
                    break;
                case 1:
                    themTTNV(dsNhanVien);
                    break;
                case 2:
                    char manv[8];
                    cout << "\nMoi ban nhap ma cua nhan vien: " << endl;
                    cin >> manv;
                    timKiemTTNVTheoMa(dsNhanVien, manv);
                    break;
                case 3:
                    cout << "\nDanh sach nhan vien cua khach san: " << endl;
                    inDanhSachNhanVien(dsNhanVien);
                    break;

                default:
                    cout << "\nChuc nang nay khong ton tai:((";
                    break;
                }
            } while (choice_2 != 0);

            break;
        case 4:
            int choice_3;
            do
            {
                MenuDichVu();
                khoiTaoDichVu(dsDichVu);
                cout << "\nMoi ban chon 1 chuc nang: ";
                cin >> choice_3;
                switch (choice_3)
                {
                case 0:
                    cout << "\nCam on ban da su dung chuc nang.";
                    break;
                case 1:
                    cout << "\nDanh sach khach hang da dang ky dich vu: " << endl;
                    hienTTKHDaDangKyDichVu(dsPhong, dsKhachHang);
                    break;
                case 2:
                    cout << "\nDanh sach dich vu cua khach san: " << endl;
                    inDanhSachDichVu(dsDichVu);
                    break;

                default:
                    cout << "\nChuc nang nay khong ton tai:((";
                    break;
                }
            } while (choice_3 != 0);

            break;
        case 5:
            int choice_4;
            do
            {
                string dataFile, dataFile1, dataFile2, dataFile3;
                MenuGhiDuLieu();
                cout << "\nMoi ban chon 1 chuc nang: ";
                cin >> choice_4;
                switch (choice_4)
                {
                case 0:
                    cout << "\nCam on ban da su dung chuc nang.";
                    break;
                case 1:
                    dataFile = "data_KhachHang.txt";
                    ghiDuLieuKH(dsKhachHang, dataFile);
                    break;
                case 2:
                    dataFile1 = "data_Phong.txt";
                    ghiDuLieuPhong(dsPhong, dataFile1);
                    break;
                case 3:
                    dataFile2 = "data_NhanVien.txt";
                    ghiDuLieuNhanVien(dsNhanVien, dataFile2);
                    break;
                case 4:
                    dataFile3 = "data_DichVu.txt";
                    ghiDuLieuDichVu(dsPhong, dsKhachHang, dsDichVu, dataFile3);
                    break;

                default:
                    cout << "\nChuc nang nay khong ton tai:((";
                    break;
                }
            } while (choice_4 != 0);

            break;
        default:
            cout << "\nChuc nang nay khong ton tai:((";
            break;
        }
    } while (chon != 0);
    cout << "\n ";
    return 0;
}

void Menu()
{
    cout << "\n-----------------------Menu-----------------------";
    cout << "\n1. Quan ly khach hang";
    cout << "\n2. Quan ly phong";
    cout << "\n3. Quan ly nhan vien";
    cout << "\n4. Quan ly dich vu";
    cout << "\n5. Ghi du lieu ra file";
    cout << "\n--------------------------------------------------";
}

void MenuKhachHang()
{
    cout << "\n------------------Menu-Khach-Hang-------------------";
    cout << "\n1. Them thong tin khach hang";
    cout << "\n2. Xoa thong tin khach hang";
    cout << "\n3. Sua thong tin khach hang";
    cout << "\n4. Thay the thong tin khac hang";
    cout << "\n5. Tim kiem thong tin khach hang the ma";
    cout << "\n----------------------------------------------------";
}

void MenuPhong()
{
    cout << "\n-------------------Menu-Phong-----------------------";
    cout << "\n1. Khach hang dang ki thue phong";
    cout << "\n2. Khach hang dang ki tra phong";
    cout << "\n3. Hien thong tin phong khach hang da thue";
    cout << "\n4. Hien thi thong tin phong con trong";
    cout << "\n----------------------------------------------------";
}

void MenuNhanVien()
{
    cout << "\n------------------Menu-Nhan-Vien--------------------";
    cout << "\n1. Nhap thong tin nhan vien";
    cout << "\n2. Tim kiem nhan vien theo ma";
    cout << "\n3. In danh sach nhan vien";
    cout << "\n----------------------------------------------------";
}

void MenuDichVu()
{
    cout << "\n-------------------Menu-Dich-Vu---------------------";
    cout << "\n1. Thong tin khach hang dang ki va su dung dich vu";
    cout << "\n2. Cac loai hinh dich vu va gia";
    cout << "\n----------------------------------------------------";
}

void MenuGhiDuLieu()
{
    cout << "\n-----------------Ghi-Du-Lieu--------------------";
    cout << "\n1. Ghi du lieu khach hang";
    cout << "\n2. Ghi du lieu phong";
    cout << "\n3. Ghi du lieu nhan vien";
    cout << "\n4. Ghi du lieu dich vu";
    cout << "\n------------------------------------------------";
}

void themTTKH(khachHang *&dsKhachHang)
{
    nhapTTKH(dsKhachHang);
}

void nhapTTKH(khachHang *&dsKhachHang)
{
    khachHang *khachHangMoi = new khachHang;
    do
    {
        cout << "\nNhap ma cua khach hang: ";
        cin >> khachHangMoi->maKH;
        if (kiemTraMaKhachHang(dsKhachHang, khachHangMoi->maKH))
        {
            cout << "\nVui long nhap lai da co ma khach hang nay!";
        }
    } while (kiemTraMaKhachHang(dsKhachHang, khachHangMoi->maKH));
    cout << "\nNhap ho ten khach hang: ";
    cin.ignore();
    cin.getline(khachHangMoi->hoTen, sizeof(khachHangMoi->hoTen));
    cout << "\nNhap gioi tinh cua khach hang: ";
    cin >> khachHangMoi->gioiTinh;
    cout << "\nNhap nam sinh cua khach hang: ";
    cin >> khachHangMoi->namSinh;
    cout << "\nNhap so CMND cua khach hang: ";
    cin >> khachHangMoi->soCMND;
    cout << "\nNhap que quan cua khach hang: ";
    cin.ignore();
    cin.getline(khachHangMoi->queQuan, sizeof(khachHangMoi->queQuan));
    cout << "\nNhap ngay thue phong cua khach hang: ";
    cin >> khachHangMoi->ngayThue;

    khachHangMoi->next = dsKhachHang;
    dsKhachHang = khachHangMoi;

    cout << "\nThem thanh cong." << endl;
}

void inDanhSachKhachHang(khachHang *dsKhachHang)
{
    cout << setw(10) << "Ma KH" << setw(25) << "Ho va Ten" << setw(10) << "Gioi Tinh" << setw(15) << "Nam Sinh" << setw(15) << "So CMND" << setw(20) << "Que Quan" << setw(15) << "Ngay Thue" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    khachHang *temp = dsKhachHang;
    while (temp != nullptr)
    {
        cout << setw(10) << temp->maKH << setw(25) << temp->hoTen << setw(10) << temp->gioiTinh << setw(15) << temp->namSinh << setw(15) << temp->soCMND << setw(20) << temp->queQuan << setw(15) << temp->ngayThue << endl;
        temp = temp->next;
    }
}

bool kiemTraMaKhachHang(khachHang *dsKhachHang, char *maKH)
{
    khachHang *temp = dsKhachHang;
    while (temp != nullptr)
    {
        if (strcmp(temp->maKH, maKH) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void xoaTTKH(khachHang *&dsKhachHang, char *maKH)
{
    if (dsKhachHang == nullptr)
    {
        cout << "\nKhong co ket qua";
        return;
    }
    khachHang *temp = dsKhachHang;
    khachHang *prev = nullptr;

    while (temp != nullptr && strcmp(temp->maKH, maKH) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "\nKhong tim thay ma khach hang ban can xoa:((" << maKH << endl;
        return;
    }

    if (prev == nullptr)
    {
        dsKhachHang = dsKhachHang->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "\nDa xoa thanh cong." << endl;
}

void suaTTKH(khachHang *dsKhachHang, char *maKH)
{
    khachHang *temp = dsKhachHang;
    while (temp != nullptr)
    {
        if (strcmp(temp->maKH, maKH) == 0)
        {
            cout << "\nNhap thong tin moi cua khach hang: ";
            cout << "\nNhap ho ten cua khach hang: ";
            cin.ignore();
            cin.getline(temp->hoTen, sizeof(temp->hoTen));
            cout << "\nNhap gioi tinh cua khach hang: ";
            cin >> temp->gioiTinh;
            cout << "\nNhap nam sinh cua khach hang: ";
            cin >> temp->namSinh;
            cout << "\nNhap so CMND cua khach hang: ";
            cin >> temp->soCMND;
            cout << "\nNhap que quan cua khach hang: ";
            cin.ignore();
            cin.getline(temp->queQuan, sizeof(temp->queQuan));
            cout << "\nNhap ngay thue phong cua khach hang: ";
            cin >> temp->ngayThue;

            cout << "\nThong tin cua khach hang da sua thanh cong." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "\nKhong tim thay ma khach hang ma ban can tim." << endl;
}

void thayTheTTKH(khachHang *&dsKhachHang, char *maKH)
{
    khachHang *temp = dsKhachHang;
    khachHang *previous = nullptr;

    while (temp != nullptr)
    {
        if (strcmp(temp->maKH, maKH) == 0)
        {
            // Xóa thông tin của khách hàng cũ
            if (previous != nullptr)
            {
                previous->next = temp->next;
            }
            else
            {
                dsKhachHang = temp->next;
            }
            delete temp;

            // Thêm thông tin mới của khách hàng
            khachHang *khachHangMoi = new khachHang;

            cout << "\nNhap ma cua khach hang moi: ";
            cin >> khachHangMoi->maKH;

            cout << "\nNhap ho ten khach hang moi: ";
            cin.ignore();
            cin.getline(khachHangMoi->hoTen, sizeof(khachHangMoi->hoTen));

            cout << "\nNhap gioi tinh khach hang moi: ";
            cin >> khachHangMoi->gioiTinh;

            cout << "\nNhap nam sinh khach hang moi: ";
            cin >> khachHangMoi->namSinh;

            cout << "\nNhap so CMND khach hang moi: ";
            cin >> khachHangMoi->soCMND;

            cout << "\nNhap que quan cua khach hang moi: ";
            cin.ignore();
            cin.getline(khachHangMoi->queQuan, sizeof(khachHangMoi->queQuan));

            cout << "\nNhap ngay thue phong khach hang moi: ";
            cin >> khachHangMoi->ngayThue;

            khachHangMoi->next = dsKhachHang;
            dsKhachHang = khachHangMoi;

            cout << "\nThong tin khach hang da duoc thay the.\n";
            return;
        }
        previous = temp;
        temp = temp->next;
    }
    cout << "\nKhong tim thay khach hang voi ma " << maKH << ".\n";
}

void timKiemTTKHTheoMa(khachHang *dsKhachHang, char *maKH)
{
    khachHang *temp = dsKhachHang;
    while (temp != nullptr)
    {
        if (strcmp(temp->maKH, maKH) == 0)
        {
            cout << "\n+--------+----------------------+----------+-----------+------------+-----------------+";
            cout << "\n| Ma KH  |       Ho Ten         |  Gioi Tinh  | Nam Sinh  |  So CMND   | Que quan | Ngay Thue Phong|";
            cout << "\n+--------+----------------------+----------+-----------+------------+-----------------+";
            cout << "\n| " << setw(6) << left << temp->maKH << " | " << setw(20) << left << temp->hoTen << " | "
                 << setw(8) << left << temp->gioiTinh << " | " << setw(9) << left << temp->namSinh << " | "
                 << setw(11) << left << temp->soCMND << " | " << setw(9) << left << temp->queQuan << " | "
                 << setw(16) << left << temp->ngayThue << " |";
            cout << "\n+--------+----------------------+----------+-----------+------------+-----------------+";
            return;
        }
        temp = temp->next;
    }
    cout << "\nKhong tim thay khach hang voi ma " << maKH << ".\n";
}

void inDanhSachPhong(phong *dsPhong)
{
    cout << setw(15) << "Ma Phong" << setw(15) << "So giuong" << setw(15) << "Tinh Trang" << endl;
    cout << "---------------------------------" << endl;

    phong *temp = dsPhong;
    while (temp != nullptr)
    {
        cout << setw(15) << temp->maPhong << setw(15) << temp->soGiuong << setw(15) << (temp->tinhTrang ? "Da thue" : "Con trong") << endl;
        temp = temp->next;
    }
}

void DKThuePhong(phong *dsPhong, char *maPhong, khachHang *dsKhachHang)
{
    phong *temp = dsPhong;
    while (temp != nullptr)
    {
        if (strcmp(temp->maPhong, maPhong) == 0)
        {
            if (temp->tinhTrang) // kiem tra phong thue chua
            {
                cout << "\nPhong nay da duoc thue. Moi ban chon phong khac." << endl;
                return;
            }

            if (dsKhachHang == nullptr) // kiem tra khach hang
            {
                cout << "\nKhong co thong tin cua khach hang nay. " << endl;
                return;
            }

            char maKH[8];
            cout << "\nNhap ma khach hang: ";
            cin >> maKH;

            khachHang *tempKH = dsKhachHang;
            while (tempKH != nullptr)
            {
                if (strcmp(tempKH->maKH, maKH) == 0)
                {
                    temp->tinhTrang = true;
                    cout << "\nDat phong thanh cong." << endl;
                    return;
                }
                tempKH = tempKH->next;
            }

            cout << "\nKhong tim thay ma cua khach hang." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "\nKhong tim thay phong." << endl;
}

void DKTraPhong(phong *dsPhong, char *maPhong, khachHang *dsKhachHang)
{
    phong *temp = dsPhong;
    while (temp != nullptr)
    {
        if (strcmp(temp->maPhong, maPhong) == 0)
        {
            if (!temp->tinhTrang)
            {
                cout << "\nPhong nay chua duoc thue." << endl;
                return;
            }

            char maKhach[8];
            cout << "\nNhap ma khach hang: ";
            cin >> maKhach;

            khachHang *tempKH = dsKhachHang;
            khachHang *prevKH = nullptr;
            while (tempKH != nullptr)
            {
                if (strcmp(tempKH->maKH, maKhach) == 0)
                {
                    if (prevKH != nullptr)
                    {
                        prevKH->next = tempKH->next;
                    }
                    else
                    {
                        dsKhachHang = tempKH->next;
                    }

                    delete tempKH;

                    // Cập nhật trang thái phòng
                    temp->tinhTrang = false;
                    cout << "\nTra phong thanh cong." << endl;
                    return;
                }
                prevKH = tempKH;
                tempKH = tempKH->next;
            }
            cout << "\nKhong tim thay thong tin cua khach hang thue phong." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "\nKhong tim thay phong." << endl;
}

void hienTTPhongDaThue(phong *dsPhong)
{
    cout << setw(15) << "Ma Phong" << setw(20) << "So giuong" << setw(20) << "Tinh trang" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;

    phong *temp = dsPhong;
    while (temp != nullptr)
    {
        if (temp->tinhTrang)
        {
            cout << setw(15) << temp->maPhong;
            cout << setw(20) << temp->soGiuong << setw(20) << "Da duoc thue" << endl;
        }
        temp = temp->next;
    }
}

void hienTTPhongConTrong(phong *dsPhong)
{
    cout << setw(15) << "Ma phong" << setw(15) << "So giuong" << setw(15) << "Tinh trang" << endl;
    cout << "--------------------------------------------------------" << endl;

    phong *temp = dsPhong;
    while (temp != nullptr)
    {
        while (!temp->tinhTrang) // Nếu phòng chưa được thuê
        {
            cout << setw(15) << temp->maPhong << setw(15) << temp->soGiuong << setw(15) << "Con trong" << endl;
            break;
        }
        temp = temp->next;
    }
}

void themTTNV(nhanVien *&dsNhanVien)
{
    nhapTTNV(dsNhanVien);
}

void nhapTTNV(nhanVien *&dsNhanVien)
{
    nhanVien *nhanVienMoi = new nhanVien;
    do
    {
        cout << "\nMoi ban nhap ma cua nhan vien: ";
        cin >> nhanVienMoi->maNV;
        if (kiemTraMaNhanVien(dsNhanVien, nhanVienMoi->maNV))
        {
            cout << "\nVui long nhap lai ma cua nhan vien.";
        }

    } while (kiemTraMaNhanVien(dsNhanVien, nhanVienMoi->maNV));
    cout << "\nNhap ho ten cua nhan vien: ";
    cin.ignore();
    cin.getline(nhanVienMoi->hoTen, sizeof(nhanVienMoi->hoTen));
    cout << "\nMoi ban nhap gioi tinh cua nhan vien: ";
    cin >> nhanVienMoi->gioiTinh;
    cout << "\nMoi ban nhap nam sinh cua nhan vien: ";
    cin >> nhanVienMoi->namsinh;
    cout << "\nMoi ban nhap chuc vu cua nhan vien: ";
    cin.ignore();
    cin.getline(nhanVienMoi->chucVu, sizeof(nhanVienMoi->chucVu));
    cout << "\nMoi ban nhap muc luong cua nhan vien: ";
    cin >> nhanVienMoi->luong;

    nhanVienMoi->next = dsNhanVien;
    dsNhanVien = nhanVienMoi;

    cout << "\nThem thanh cong." << endl;
}

bool kiemTraMaNhanVien(nhanVien *dsNhanVien, char *maNV)
{
    nhanVien *temp = dsNhanVien;
    while (temp != nullptr)
    {
        if (strcmp(temp->maNV, maNV) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void timKiemTTNVTheoMa(nhanVien *dsNhanVien, char *maNV)
{
    cout << "\nThong tin cua nhan vien can tim: ";
    nhanVien *temp = dsNhanVien;
    while (temp != nullptr)
    {
        if (strcmp(temp->maNV, maNV) == 0)
        {
            cout << "\n+--------+----------------------+----------+-----------+------------+------------+";
            cout << "\n| Ma NV  |       Ho Ten         |  Gioi Tinh  | Nam Sinh  |  Chuc vu  | Luong |";
            cout << "\n+--------+----------------------+----------+-----------+------------+------------+";
            cout << "\n| " << setw(6) << left << temp->maNV << " | " << setw(20) << left << temp->hoTen << " | "
                 << setw(8) << left << temp->gioiTinh << " | " << setw(9) << left << temp->namsinh << " | "
                 << setw(11) << left << temp->chucVu << " | " << setw(9) << fixed << setprecision(0) << temp->luong << "VND"
                 << " | ";
            cout << "\n+--------+----------------------+----------+-----------+------------+------------+";
            return;
        }
        temp = temp->next;
    }
    cout << "\nKhong tim thay khach hang voi ma " << maNV << ".\n";
}

void inDanhSachNhanVien(nhanVien *dsNhanVien)
{
    cout << setw(10) << "Ma NV" << setw(25) << "Ho va Ten" << setw(10) << "Gioi Tinh" << setw(15) << "Nam Sinh" << setw(15) << "Chuc vu" << setw(20) << "Muc luong" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    nhanVien *temp = dsNhanVien;
    while (temp != nullptr)
    {
        cout << setw(10) << temp->maNV << setw(25) << temp->hoTen << setw(10) << temp->gioiTinh << setw(15) << temp->namsinh << setw(15) << temp->chucVu << setw(20) << fixed << setprecision(0) << temp->luong << "VND" << endl;
        temp = temp->next;
    }
}

void hienTTKHDaDangKyDichVu(phong *dsPhong, khachHang *dsKhachHang)
{
    cout << setw(15) << "Ma Phong" << setw(15) << "Ma KH" << setw(30) << "Ten khach hang" << setw(20) << "So CMND" << setw(10) << "Que quan" << setw(15) << "Ngay thue" << setw(15) << "So giuong" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;

    phong *temp = dsPhong;
    while (temp != nullptr)
    {
        while (temp->tinhTrang) // nếu phòng đã được thuê
        {
            cout << setw(15) << temp->maPhong;
            khachHang *tempKH = dsKhachHang;
            while (tempKH != nullptr)
            {
                if (strcmp(tempKH->maKH, tempKH->maKH) == 0)
                {
                    cout << setw(15) << tempKH->maKH << setw(30) << tempKH->hoTen << setw(20) << tempKH->soCMND << setw(10) << tempKH->queQuan << setw(15) << tempKH->ngayThue << setw(15) << temp->soGiuong << endl;
                    break;
                }
                tempKH = tempKH->next;
            }
            break;
        }
        temp = temp->next;
    }
}

void khoiTaoDichVu(dichVu *&dsDichVu)
{
    dichVu *dvPhong1Giuong = new dichVu;
    strcpy(dvPhong1Giuong->tenDV, "Dich vu phong 1 giuong");
    dvPhong1Giuong->gia = 700000;
    dvPhong1Giuong->trangThai = true;
    dvPhong1Giuong->next = nullptr;

    dichVu *dvPhong2Giuong = new dichVu;
    strcpy(dvPhong2Giuong->tenDV, "Dich vu phong 2 giuong");
    dvPhong2Giuong->gia = 900000;
    dvPhong2Giuong->trangThai = true;
    dvPhong2Giuong->next = nullptr;

    dvPhong1Giuong->next = dvPhong2Giuong;

    dsDichVu = dvPhong1Giuong;
}

void inDanhSachDichVu(dichVu *dsDichVu)
{
    cout << "Danh sach dich vu:" << endl;
    cout << left << setw(25) << "Ten dich vu" << setw(15) << "Gia" << setw(15) << "Trang thai" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    while (dsDichVu != nullptr)
    {
        cout << left << setw(25) << dsDichVu->tenDV << setw(15) << dsDichVu->gia << setw(15) << (dsDichVu->trangThai ? "San sang" : "Khong san sang") << endl;
        dsDichVu = dsDichVu->next;
    }
}

void ghiDuLieuKH(khachHang *dsKhachHang, const string &data_KH)
{
    ofstream outFile(data_KH);
    const khachHang *temp = dsKhachHang;
    outFile << "\n---------------------------File-Du-Lieu-Khach-Hang-------------------------------" << endl;
    outFile << setw(10) << "Ma KH" << setw(25) << "Ho va Ten" << setw(10) << "Gioi Tinh" << setw(15) << "Nam Sinh" << setw(15) << "So CMND" << setw(20) << "Que Quan" << setw(15) << "Ngay Thue" << endl;
    outFile << "\n-------------------------------------------------------------------------------------------" << endl;

    while (temp != nullptr)
    {
        outFile << setw(10) << temp->maKH << setw(25) << temp->hoTen << setw(10) << temp->gioiTinh << setw(15) << temp->namSinh << setw(15) << temp->soCMND << setw(20) << temp->queQuan << setw(15) << temp->ngayThue << endl;
        temp = temp->next;
    }
    outFile.close();
    cout << "\nGhi du lieu thong tin khach hang thanh cong.";
}

void ghiDuLieuPhong(phong *dsPhong, const string &data_Phong)
{
    ofstream outFile(data_Phong);
    const phong *temp = dsPhong;
    outFile << "--------Ghi-Du-Lieu-Phong---------" << endl;
    outFile << setw(15) << "Ma Phong" << setw(15) << "So giuong" << setw(15) << "Tinh Trang" << endl;
    outFile << "----------------------------------" << endl;

    while (temp != nullptr)
    {
        outFile << setw(15) << temp->maPhong << setw(15) << temp->soGiuong << setw(15) << (temp->tinhTrang ? "Da thue" : "Con trong") << endl;
        temp = temp->next;
    }
    outFile.close();
    cout << "\nGhi du lieu phong thanh cong.";
}

void ghiDuLieuNhanVien(nhanVien *dsNhanVien, const string &data_NhanVien)
{
    ofstream outFile(data_NhanVien);
    const nhanVien *temp = dsNhanVien;
    outFile << "--------------------------------------------Ghi-Du-Lieu-Nhan-Vien-----------------------------------------------------" << endl;
    outFile << setw(10) << "Ma NV" << setw(25) << "Ho va Ten" << setw(10) << "Gioi Tinh" << setw(15) << "Nam Sinh" << setw(15) << "Chuc vu" << setw(20) << "Muc luong" << endl;
    outFile << "---------------------------------------------------------------------------------------------------------------------" << endl;

    while (temp != nullptr)
    {
        outFile << setw(10) << temp->maNV << setw(25) << temp->hoTen << setw(10) << temp->gioiTinh << setw(15) << temp->namsinh << setw(15) << temp->chucVu << setw(20) << fixed << setprecision(0) << temp->luong << endl;
        temp = temp->next;
    }
    outFile.close();
    cout << "\nGhi du lieu nhan vien thanh cong.";
}

void ghiDuLieuDichVu(phong *dsPhong, khachHang *dsKhachHang, dichVu *dsDichVu, const string &data_DichVu)
{
    ofstream outFile(data_DichVu);
    const phong *temp = dsPhong;

    outFile << "----------------------------------------Danh-Sach-Khach-Su-Dung-Dich-Vu--------------------------------------------" << endl;
    outFile << setw(15) << "Ma Phong" << setw(15) << "Ma KH" << setw(30) << "Ten khach hang" << setw(20) << "So CMND" << setw(25) << "Que quan" << setw(15) << "Ngay thue" << setw(15) << "So giuong" << endl;
    outFile << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;

    while (temp != nullptr)
    {
        while (temp->tinhTrang)
        {
            outFile << setw(15) << temp->maPhong;
            const khachHang *tempKH = dsKhachHang;
            while (tempKH != nullptr)
            {
                if (strcmp(tempKH->maKH, tempKH->maKH) == 0)
                {
                    outFile << setw(15) << tempKH->maKH << setw(30) << tempKH->hoTen << setw(20) << tempKH->soCMND << setw(25) << tempKH->queQuan << setw(15) << tempKH->ngayThue << setw(15) << temp->soGiuong << endl;
                    break;
                }
                tempKH = tempKH->next;
            }
            break;
        }
        temp = temp->next;
    }

    outFile << "---------------------------------------Danh-Sach-Dich-Vu------------------------------------------" << endl;
    outFile << setw(25) << "Ten dich vu" << setw(15) << "Gia" << setw(15) << "Trang thai" << endl;
    outFile << "-------------------------------------------------------------------" << endl;
    while (dsDichVu != nullptr)
    {
        outFile << setw(25) << dsDichVu->tenDV << setw(15) << dsDichVu->gia << setw(15) << (dsDichVu->trangThai ? "San sang" : "Khong san sang") << endl;
        dsDichVu = dsDichVu->next;
    }

    outFile.close();
    cout << "\nGhi du lieu dich vu thanh cong.";
}