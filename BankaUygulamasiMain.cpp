#include <iostream>
#include <string>
using namespace std;


class Musteri
{
private:	
    int MusteriNo;
    string MusteriAd;
    int MusteriTur;
public:
	void setMusteriNo(int MusteriNo){this->MusteriNo = MusteriNo;}
	void setMusteriAd(string MusteriAd){this->MusteriAd = MusteriAd;} 
	void setMusteriTur(int MusteriTur){this->MusteriTur = MusteriTur;} 
	
	int getMusteriNo(){return MusteriNo;} 
	string getMusteriAd(){return MusteriAd;} 
	int getMusteriTur(){return MusteriTur;}    
	
	void listele(Musteri [],int uzunluk);
};

class Tarih
{
private:
	double FaturaTarihi;
	double AktarmaTarihi;
	double AcilmaTarihi;
	int HesapNo;
	double FaturaMiktari;
	double AktarilanParaMiktari;
	int MusteriNo;
public:
	void setFaturaTarihi(double FaturaTarihi){this->FaturaTarihi = FaturaTarihi;}
	void setAktarmaTarihi(double AktarmaTarihi){this->AktarmaTarihi = AktarmaTarihi;}
	void setAcilmaTarihi(double AcilmaTarihi){this->AcilmaTarihi = AcilmaTarihi;}
	void setHesapNo(int HesapNo){this->HesapNo = HesapNo;} 
	void setFaturaMiktari(double FaturaMiktari){this->FaturaMiktari = FaturaMiktari;}
	void setAktarilanParaMiktari(double AktarilanParaMiktari){this->AktarilanParaMiktari = AktarilanParaMiktari;}
	void setMusteriNo(int MusteriNo){this->MusteriNo = MusteriNo;}
	
	double getFaturaTarihi(){return FaturaTarihi;}
	double getAktarmaTarihi(){return AktarmaTarihi;}
	double getAcilmaTarihi(){return AcilmaTarihi;}
	int getHesapNo(){return HesapNo;} 
	double getFaturaMiktari(){return FaturaMiktari;}
	double getAktarilanParaMiktari(){return AktarilanParaMiktari;}
	int getMusteriNo(){return MusteriNo;} 
	
	friend ostream &operator<< (ostream&, Tarih&);
};

ostream& operator<<(ostream &os, Tarih &n)
{
     os <<"\n\tHesap No:"<<n.getHesapNo()<<"\n\tMusteri No:"<<n.getMusteriNo()<<"\n\tAcilma Tarihi:"<< n.getAcilmaTarihi()<<"\n\tAktarma Tarihi:"<<n.getAktarmaTarihi()<<
	 "\n\tAktarilan Para Miktari:"<< n.getAktarilanParaMiktari()<<"\n\tFatura Tarihi:"<<n.getFaturaTarihi()<<"\n\tFatura Miktari:"<<n.getFaturaMiktari()<<endl;
     return os;
}


void Musteri :: listele(Musteri  Musteri[],int uzunluk)
{
	
	cout<<"\n\t\tMusteri Listesi"<<endl;
	for(int j=0; j<uzunluk; j++)
	{	
		cout<<"\tMusteri No:    "<<Musteri[j].getMusteriNo()<<endl;
		cout<<"\tMusteri Ad:    "<<Musteri[j].getMusteriAd()<<endl;
		if(Musteri[j].getMusteriTur() == 1)
		{
			cout<<"\tMusteri Tur:    Kurumsal Musteri\n"<<endl;
		}	
		else if(Musteri[j].getMusteriTur() == 2)
		{
			cout<<"\tMusteri Tur:    Bireysel Musteri\n"<<endl;
		}
			
	}
}





class Hesap
{
private:
	int MusteriNo;	
    int HesapNo;
	int Miktar;
public:
	void setMusteriNo(int MusteriNo){this->MusteriNo = MusteriNo;}
	void setHesapNo(int HesapNo){this->HesapNo = HesapNo;} 
	void setMiktar(int Miktar){this->Miktar = Miktar;} 
	
	int getMusteriNo(){return MusteriNo;} 
	int getHesapNo(){return HesapNo;} 
	int getMiktar(){return Miktar;}    
	
	void listele(Hesap [],int uzunluk);
};


void Hesap :: listele(Hesap  Hesap[],int uzunluk)
{
	
	cout<<"\n\t\tHesaplarin Listesi"<<endl;
	for(int j=0; j<uzunluk; j++)
	{	
		cout<<"\n\tHesap No:        "<<Hesap[j].getHesapNo()<<endl;
		cout<<"\tMusteri No:      "<<Hesap[j].getMusteriNo()<<endl;
		cout<<"\tHesap Miktar:    "<<Hesap[j].getMiktar()<<endl;
		
	}
}

int MusteriKontrol(Musteri Musteri[],int MusteriNo,int uzunluk)
{
	int MusteriKontrol=0;
	do{
		for(int j=0;j<uzunluk;j++)
		{
			if(Musteri[j].getMusteriNo() == MusteriNo)
			{
				
				MusteriKontrol=1;
			}
		}
				
		if(MusteriKontrol==0)
		{
			cout << "\n\tBoyle Bir Musteri Bulunmamaktadir!! Lutfen Bulunan bir musteri numarasi giriniz:  "; cin >> MusteriNo;
		}
				
	}while(MusteriKontrol==0);
	
	return MusteriNo;
}

int HesapKontrol(Hesap Hesap[],int HesapNo,int uzunluk)
{
	int HesapKontrol=0;
	do{
		for(int j=0;j<uzunluk;j++)
		{
			if(Hesap[j].getHesapNo() == HesapNo)
			{
				
				HesapKontrol=1;
			}
		}
				
		if(HesapKontrol==0)
		{
			cout << "\n\tBoyle Bir Hesap Bulunmamaktadir!! Lutfen Bulunan bir hesap numarasi giriniz:  "; cin >> HesapNo;
		}
				
	}while(HesapKontrol==0);
	
	return HesapNo;
}

int main() {
	int MusteriNo,HesapNo,HesapNo2,fatura;
    string MusteriAd;
    int MusteriTur;
    int Miktar,AktarilanPara;
    double FaturaTarihi;
	double AktarmaTarihi;
	double AcilmaTarihi;
	
    Musteri Musteri[30];
    Hesap Hesap[30];
    Tarih Tarih[30];
    
    Musteri[0].setMusteriNo(1), Musteri[0].setMusteriAd("Burak"), Musteri[0].setMusteriTur(1);
    Musteri[1].setMusteriNo(2), Musteri[1].setMusteriAd("Cengiz"), Musteri[1].setMusteriTur(2);
    Hesap[0].setMusteriNo(1), Hesap[0].setHesapNo(1), Hesap[0].setMiktar(1500);
    Hesap[1].setMusteriNo(2), Hesap[1].setHesapNo(2), Hesap[1].setMiktar(3500);
    Hesap[2].setMusteriNo(2), Hesap[2].setHesapNo(3), Hesap[2].setMiktar(500);
    Tarih[0].setHesapNo(1), Tarih[0].setFaturaTarihi(2015), Tarih[0].setAktarmaTarihi(2012), Tarih[0].setAcilmaTarihi(1950);
	Tarih[0].setAktarilanParaMiktari(500),Tarih[0].setFaturaMiktari(300),Tarih[0].setMusteriNo(1);
    Tarih[1].setHesapNo(2), Tarih[1].setFaturaTarihi(2013), Tarih[1].setAktarmaTarihi(2017), Tarih[1].setAcilmaTarihi(1960);
	Tarih[1].setAktarilanParaMiktari(300),Tarih[1].setFaturaMiktari(800),Tarih[1].setMusteriNo(2);
    Tarih[2].setHesapNo(3), Tarih[2].setFaturaTarihi(2018), Tarih[2].setAktarmaTarihi(2014), Tarih[2].setAcilmaTarihi(1938);
	Tarih[2].setAktarilanParaMiktari(1100),Tarih[2].setFaturaMiktari(500),Tarih[2].setMusteriNo(2);
    
	int secim,kontrol,i=2,a=3,b=3,MusteriKontrol2=0;
	
	
	cout << "\n\tBanka Uygulamasina Hosgeldiniz" << endl;
	do{
		cout <<"\n\t\tMENU"<<endl;
		cout <<"\n\t1-Yeni Musteri Ekle\n\t2-Yeni Hesap acma\n\t3-Para Aktarma\n\t4-Odeme Yapma\n\t5-Hesap Ozeti" << endl;
		cout <<"\n\tLutfen yapmak istediginiz islemi seciniz:  ";	cin >> secim;
		while(secim<1 || secim>5)
		{
			cout <<"\n\n\tLutfen Menudeki sayilardan secim yapiniz:  "; cin >> secim;
		}
		
		if(secim == 1)
		{
			Musteri[0].listele(Musteri,i);
			
			cout << "\n\t\tMusteri Eklemeye Hosgeldiniz" << endl;
			cout << "\n\tMusterinin Adini giriniz:  "; cin >> MusteriAd;
			cout << "\n\tMusterinin Turunu Seciniz:\n  "<<"Kurumsal musteri >> 1 \t Bireysel musteri >> 2 :  "; cin >> MusteriTur;
			while(MusteriTur<1 || MusteriTur>2)
			{
				cout <<"\n\tLutfen Menudeki sayilardan secim yapiniz:  \n" << endl;
				cout << "\tKurumsal musteri >> 1 \t Bireysel musteri >> 2 :  "; cin >> MusteriTur;
			}
			Musteri[i].setMusteriNo(i+1);
			Musteri[i].setMusteriAd(MusteriAd);
			Musteri[i].setMusteriTur(MusteriTur);
			i++;
			
			Musteri[0].listele(Musteri,i);
		}
		
		
		
		if(secim == 2)
		{
			cout << "\n\tYeni Hesap Acmaya Hosgeldiniz" << endl;
			Musteri[0].listele(Musteri,i);
			cout << "\tMusteri Numarasi giriniz:  "; cin >> MusteriNo;
			Hesap[a].setMusteriNo(MusteriKontrol(Musteri,MusteriNo,i));			
			cout << "\n\tHesabin miktarini giriniz:  "; cin >> Miktar;
			cout << "\n\tHesabin acilis tarihini giriniz(1900-2100):  "; cin >> AcilmaTarihi;
			Hesap[a].setMiktar(Miktar);
			Hesap[a].setHesapNo(a+1);
			Tarih[b].setAcilmaTarihi(AcilmaTarihi);
			Tarih[b].setHesapNo(b+1);
			Tarih[b].setMusteriNo(MusteriNo);
			b++;
			a++;
			Hesap[0].listele(Hesap,a);
		}
		
		
		
		if(secim == 3)
		{
			Hesap[0].listele(Hesap,a);
			
			cout << "\n\t\tPara Aktarmaya Hosgeldiniz" << endl;
			cout <<"\n\tLutfen Hesap Numarasi giriniz:   ";cin >> HesapNo;
		    HesapKontrol(Hesap,HesapNo,a);
			cout <<"\n\tPara gondermek istediginiz Hesap numarasini giriniz:  ";cin >> HesapNo2;
			HesapKontrol(Hesap,HesapNo2,a);
			cout <<"\n\tAktarmak istediniz miktari giriniz:   ";cin>>AktarilanPara;
			cout <<"\n\tTarihi giriniz(1900-2100):   ";cin>>AktarmaTarihi;
			
			for(int j=0;j<b;j++)
			{
				if(Tarih[j].getHesapNo()==HesapNo)
				{
					Tarih[j].setAktarmaTarihi(AktarmaTarihi);
					Tarih[j].setAktarilanParaMiktari(AktarilanPara);
				}
			}
			
			
			MusteriNo=Hesap[HesapNo-1].getMusteriNo();
			
			if(Hesap[HesapNo-1].getMiktar() >= AktarilanPara )
			{
				Hesap[HesapNo-1].setMiktar(Hesap[HesapNo-1].getMiktar()-AktarilanPara);
				Hesap[HesapNo2-1].setMiktar(Hesap[HesapNo2-1].getMiktar()+AktarilanPara);
			}
			else
			{
				Hesap[HesapNo2-1].setMiktar(Hesap[HesapNo2-1].getMiktar()+Hesap[HesapNo-1].getMiktar());
				AktarilanPara -= Hesap[HesapNo-1].getMiktar();
				Hesap[HesapNo-1].setMiktar(0);
				for(int j=0;j<a;j++)
				{
					if(Hesap[j].getMusteriNo() == MusteriNo)
					{
						
						if(Hesap[j].getMiktar() != 0)
						{
							
							if(Hesap[j].getMiktar() > AktarilanPara)
							{
								Hesap[HesapNo2-1].setMiktar(Hesap[HesapNo2-1].getMiktar()+AktarilanPara);
								Hesap[j].setMiktar(Hesap[j].getMiktar()-AktarilanPara);
							}
							else
							{
								Hesap[HesapNo2-1].setMiktar(Hesap[HesapNo2-1].getMiktar()+Hesap[j].getMiktar());
								Hesap[j].setMiktar(0);
							}
						}		
					}
				}
			}
			
			Hesap[0].listele(Hesap,a);
		}
		
		
		if(secim == 4)
		{
			Hesap[0].listele(Hesap,a);
			
			cout << "\n\t\tOdeme Bolumune Hosgeldiniz" << endl;
			cout <<"\n\tLutfen Hesap Numarasi giriniz:   ";cin >> HesapNo;
			HesapKontrol(Hesap,HesapNo,a);
			cout << "\n\tLutfen bu ayki faturanizi giriniz:  ";cin >> fatura;
			cout << "\n\tTarihi giriniz(1900-2100):  ";cin >> FaturaTarihi;
			
			for(int j=0;j<b;j++)
			{
				if(Tarih[j].getHesapNo()==HesapNo)
				{
					Tarih[j].setFaturaTarihi(FaturaTarihi);
					Tarih[j].setFaturaMiktari(fatura);
				}
			}
			
			
			if(Hesap[HesapNo-1].getMiktar() >= fatura)
				Hesap[HesapNo-1].setMiktar(Hesap[HesapNo-1].getMiktar()-fatura);
			else
				cout <<"\n\tHesapta Yeterli Para bulunmamaktadir!!"<<endl;
			
			Hesap[0].listele(Hesap,a);
		}
		
		if(secim == 5)
		{
			cout << "\n\t\tOzet Bolumune Hosgeldiniz" << endl;
			cout <<"\n\tLutfen Ozetini Gormek istediginiz Hesap Numarasi giriniz:   ";cin >> HesapNo;
			HesapKontrol(Hesap,HesapNo,a);
			
			for(int j=0;j<b;j++)
			{
				if(Tarih[j].getHesapNo() == HesapNo)
				{
					cout << Tarih[j]<<endl;
				}
			}
			
		}	
		cout <<"\n\tMenuye Donmek icin 1'e Programdan cikmak icin 2'ye basiniz:  "; cin >> kontrol;
		
	}while(kontrol==1);
	 
	return 0;
}
