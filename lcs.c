#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
clock_t start_t, end_t;
double time,time1;
int i,j,m,n,lenght,lenght1,k,k1;
int xy[30][30],x1[30],y1[30],xy1[30][30],lsc1[30];
char x[30],y[30],lsc[30];
printf("        *              * * *        * * *   \n");
printf("        *            *       *    *      *    \n");
printf("        *            *            *          \n");
printf("   ***  *            *              * * *   ***   \n");
printf("        *            *                    *  \n");
printf("        *            *       *    *       *   \n");
printf("        * * * * *      * * *       * * * *     \n");

printf("\n1.dizinizin eleman sayisini giriniz.\n");
scanf("%d",&m);
printf("1.dizinizin elemanlarini giriniz.\n");
scanf("%s",x);
printf("2.dizinizin eleman sayisini giriniz.\n");
scanf("%d",&n);
printf("2.dizinizin elemanlarini giriniz.\n");
scanf("%s",y);
//Dinamik yöntemle çözebilmek için boyutu dizilerin eleman sayılarından bir fazla olan matris tanımladım.
start_t = clock();  //işlemlerin başlangıcını ölçebilmek için
//matrisin 0.satır ve sütununu 0 a eşitledim.
for (i=0;i<m+1;i++) {
 for (j=0;j<n+1;j++) {
   if (i==0 || j==0) {
     xy[i][j]=0;
   }
 }
}
//Matrisi doldurmak için;
for (i=1;i<m+1;i++){               //0.satır ve sutun 0 ile doldugundan 1.satır ve sutundan basladım.
    for (j=1;j<n+1;j++) {
      if (x[i-1] == y[j-1]) {      //Girilen dizilerin elemanlarını tek tek karşılaştırdım ve eşitse matrisin
        xy[i][j]=xy[i-1][j-1]+1;   //ilgli elemanının sol üst tarafındaki değere bir ekleyerek matrisi doldurdum.
      }
      else {
      if (xy[i-1][j] >= xy[i][j-1]) {   //Eşitlik yok ise matrisin ilgili elemanının sol ve üst elemanlarını karşılaştırdım
        xy[i][j] = xy[i-1][j];          //Hangisi daha büyük ise matrisi o değer ile doldurdum.
      }
      else {
        xy[i][j] = xy[i][j-1];
      }
    }
    }
}
lenght=xy[m][n];        //lsc nin uzunluğu matrisin son elemanına eşit oluyor.
printf("LCS nin uzunlugu:%d\n",lenght);
if (lenght==0) {   //Altkümenin uzunluğu 0 ise yoktur o sebeple altkümenin elemanlarını bulunamaz.
  printf("Girdiginiz dizilerin alt kumesi yoktur.\n");
}
else{
  i=m;
  j=n;
  k1=lenght;                  //altkümenin elemanlarini bulmak için;matrisin son elemanından başlayarak geriye doğru gittim.
while (i!=0 && j!=0) {    //while döngüsünün içinde 2 dizinin elemanlarının tamamının karşılaştırılmasını kontrol ettim.Bunu da indisler ile yaptım.
  if (x[i-1]==y[j-1]) {   //lsc nin elemanları matris oluştururken  eşlenen elemanlar o sebeple elemanların eşlendiğini kontrol ettim.
    lsc[k1-1]=x[i-1]; //eşeleşme var ise elemanı yeni bir diziye yerleştirdim.tersten gittiğim için son elemana koydum.
    i--;                 //eşleşen elemanlar matrisi oluştururken sol üst değerin bir fazlası oladuğu için tabloda o yönde ilerledim.
    j--;
    k1--;           //lsc nin elemanlarını kaydedebilmek için indisi azalttım.
  }
  else{
    if (xy[i][j-1]>=xy[i-1][j]) {  //eşelşme yok ise de yine matrisi oluştururken izlediğim yolu kullanıp  sol ya da üst değerden hangisini aldıysam
      j--;                         //matris üzerinde o elemana ilerledim.
    }
    else{
      i--;
    }
  }
}

printf("Girilen dizilerin LSC si:");
for (i = 0; i < lenght; i++) {  //lsc nin elemanlarını bastırdım.
  printf("%c",lsc[i] );
}
end_t = clock();    //işlemlerin bitiş noktası
time=(double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("\nCPU sureci (saniye): %f\n", time); //işlem süresinin hesaplanıp bastırılması
time=time*1000;   //Çok kısa bir zaman aralığında işlem yapıldığından zamanı 1000 ile çarptım.
printf("Sure:");  //Sürenin gösterimi için ise kutucuk kullanmaya karar verdim.
for (i=0;i<time; i++) {
  printf("|_| ");
}
start_t = clock();   // Farklı veri tiplerinin çalışma zamanına etkisinin analizini yapmayı seçtim.
for (i=0;i<m;i++) {  //Bu sınamayı da ilk girilen karakter dizisi değerlerini ascii tablosundaki karşılıklarına çevirerek yaptım.
  x1[i]=x[i];        //Yukarıdaki işlemlerin aynısını int dizisinde de uyguladım.
}                    //Sonuçların daha güvenilir olması için olabildiğince tam olarak aynı işlemleri yapmaya çalıştım.
for (i=0;i<n;i++) {  //Örn. karakter dizisini puts ile bastırmak yerine döngü kullandım.
  y1[i]=y[i];
}

for (i=0;i<m+1;i++) {
 for (j=0;j<n+1;j++) {
   if (i==0 || j==0) {
     xy1[i][j]=0;
   }
 }
}
for (i=1;i<m+1;i++){
    for (j=1;j<n+1;j++) {
      if (x1[i-1] == y1[j-1]) {
        xy1[i][j]=xy1[i-1][j-1]+1;
      }
      else {
      if (xy1[i-1][j] >= xy1[i][j-1]) {
        xy1[i][j] = xy1[i-1][j];
      }
      else {
        xy1[i][j] = xy1[i][j-1];
      }
    }
    }
}
lenght1=xy1[m][n];
printf("\nLCS nin uzunlugu-ascii tablosundaki degerleri ile-:%d\n",lenght1);
i=m;
j=n;
k=lenght1;
while (i!=0 && j!=0) {
  if (x1[i-1]==y1[j-1]) {
    lsc1[k-1]=x1[i-1];
    i--;
    j--;
    k--;
  }
  else{
    if (xy1[i][j-1]>=xy1[i-1][j]) {
      j--;
    }
    else{
      i--;
    }
  }
}
printf("Girilen dizilerin LSC si-ascii tablosundaki degerleri ile-:\n");
for (i=0;i<lenght1;i++) {
  printf("%d",lsc1[i] );
}

end_t = clock();
time1=(double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("\nCPU sureci (saniye): %f\n", time1);
time1=time1*1000;
printf("Sure:");
for (i=0;i<time1; i++) {
  printf("|_| ");
}
}
}
