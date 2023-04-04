#include<iostream>
#include<locale.h>  
using namespace std;
class insan {
private:
	int para = 0;
public:
	char* isim = (char*)malloc(sizeof(char) * 20);
	char* soyisim = (char*)malloc(sizeof(char) * 20);
	void setPara(int p) { 
		para += p; 
	}
	int getPara(){
		return para;
	}
};
class ATM {
private:
	int bakiye =500; 
public:
	void setBakiye(int b) {
		bakiye += b;
	}
	int getBakiye() {
		return bakiye; 
	}
};
int main() {
	setlocale(LC_ALL, "Turkish");  
	char* ad = (char*)malloc(sizeof(char)*20); 
	char* soyad = (char*)malloc(sizeof(char) * 20); 
	int islem{0}; 
	insan kullanıcı1;
	ATM makine1;
	cout << "Lütfen adınızı giriniz: ";
	cin >> ad;
	cout << "Lütfen soyadınızı giriniz ";
	cin >> soyad; 
	kullanıcı1.isim = ad; 
	kullanıcı1.soyisim = soyad;
	while (islem!=4) { 
		cout << "Yapmak istediğiniz işlemi seçiniz" << endl;
		cout << "1. Para Yatırma" << endl;
		cout << "2. Para Çekme" << endl;
		cout << "3. Bakiye ve İşlem Sonucu Kontrolü" << endl;
		cout << "4. Çıkış Yap" << endl;
		cin >> islem;
		if (islem == 1) {
			int tutar;
			cout << "Lütfen yatıralacak tutarı giriniz:";
			cin >> tutar;
			if (tutar <= 9000) {
				kullanıcı1.setPara(tutar);
				cout << "Kullanıcı: " << kullanıcı1.isim << " " << kullanıcı1.soyisim << endl;
				cout << "Yapılacak işlem = " << tutar << "TL Para Yatırma" << endl;
				cout << "İşleminiz başarıyla gerçekleştirilmiştir!" << endl;
				makine1.setBakiye(tutar);
				cout << endl;
			}
			else {
				cout << "İşleminiz gerçekleştirilememiştir!" << endl;
				cout << "Tek seferde en fazla 9000TL yatırabilirsniz!" << endl;
				cout << endl;
			}
		}
		else if (islem == 2) {
			int tutar;
			cout << "Lütfen çekilecek tutarı giriniz:";
			cin >> tutar;
			if (tutar > 9000) {
				cout<<"İşleminiz gerçekleştirilememiştir!" << endl; 
				cout << "Tek seferde en fazla 9000TL çekebilirsniz" << endl;
				cout << endl; 
			}
			else if (makine1.getBakiye() < tutar) { 
				cout << "İşleminiz gerçekleştirilemiyor! En fazla " << makine1.getBakiye() << "TL çekim yapabilirsiniz!" << endl;
				cout << endl;
			}
			else {
				kullanıcı1.setPara(tutar * -1);  
				cout << "Kullanıcı: " << kullanıcı1.isim << " " << kullanıcı1.soyisim << endl;
				cout << "Yapılan işlem = " << tutar << "TL Para Çekme" << endl;
				makine1.setBakiye(-tutar);
				cout << endl; 
			}
		}
		else if (islem == 3) {
			cout << "Kullanıcı: " << kullanıcı1.isim << " " << kullanıcı1.soyisim << endl;
			cout << "Bakiyeniz: " << makine1.getBakiye() << "TL" << endl;
			cout << "Şimdiye kadar yapılan işlemler toplamı = " << kullanıcı1.getPara() << "TL" << endl;
			cout << endl;
		} 
		else if (islem == 4) {
			cout << "Çıkış Yapıldı" << endl;
			return 0;
		}
		else {
			cout << "Lütfen geçerli bir sayı giriniz (1-2-3-4)" << endl;
			cout << endl; 
		}
	}
	return 0;
}