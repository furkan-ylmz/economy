#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

class Kisi{
	
	private:
		long long int para;

	public:
		Kisi(long long int para){setpara(para);}
		Kisi(){}
		~Kisi(){}

		void setpara(long long int para){this->para=para;}

		long long int getpara(){return para;}
};

vector<Kisi> Kisiler;

void kisi_olustur(long long int kisi,long long para){
	
	for(int i=0;i<kisi;i++){
		Kisiler.push_back(Kisi(para));
	}
}

long long int alisveris(){
	
	srand(time(NULL));

	long long int fiyat,sayi;

	cout<<"Kac kere alisveris yaptirmak istediginizi giriniz: ";
	cin>>sayi;
	cout<<"Alisveris ucretini giriniz: ";
	cin>>fiyat;
	
	for(long long int i=0;i<sayi;i++){
		
		long long int kisi1=rand()%int(Kisiler.size());
		long long int kisi2=rand()%int(Kisiler.size());

		Kisiler[kisi1].setpara(Kisiler[kisi1].getpara()+fiyat);
		Kisiler[kisi2].setpara(Kisiler[kisi2].getpara()-fiyat);
	}
	
	cout<<"Alisveris tamamlandı."<<endl;

	return fiyat;
}

void dosya_yaz(long long int fiyat){
	
	ofstream yaz("kisiler.txt",ios::out);
	
	yaz<<fiyat<<endl;

	for(int i=0;i<Kisiler.size();i++){
		yaz<<i+1<<". kisinin kalan parasi: "<<Kisiler[i].getpara()<<endl;
	}
}

void kac_kisi(long long int para,long long int fiyat){
	
	ofstream yaz("grafik.txt",ios::out);

	for(int i=1000*-para;i<=1000*para;i+=fiyat){
		long long int sayac=0;

		for(int j=0;j<Kisiler.size();j++){
			if(Kisiler[j].getpara()==i){sayac+=1;}
		}

		if(sayac!=0){
			cout<<left<<setw(5)<<i<<" parasi olan "<<setw(5)<<sayac<<" kisi vardır."<<endl;

			ofstream yaz("grafik.txt",ios::out|ios::app);

			yaz<<i<<" "<<sayac<<endl;
		}
   	}
}

int main(){
	
	long long int kisi,para;

	cout<<"Alisveris yaptirmak istediğiniz kisi sayisini girin: ";
	cin>>kisi;

	cout<<"Kisilerin baslangicta sahip oldukları para degerini girin: ";
	cin>>para;

	kisi_olustur(kisi,para);
	long long int tmp=alisveris();
	kac_kisi(para,tmp);
	dosya_yaz(tmp);

	return 0;
}