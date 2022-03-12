/////////////////////////////////////////////////////////////////
//                    özel_LCD.c                           //////
// Bu LCD sürücü dosyasý 2x16 HD44780 uyumlu LCD'ler        /////
// için yazýlmýþtýr. LCD'den sadece okuma yapýlacaðý için   /////
// R/W ucu þaseye baðlanmalýdýr. LCD baðlantýsý aþaðýdadýr. /////
// Bu LCD dosyasý ile özel karakterler de LCD gösterilebilinir //
/////////////////////////////////////////////////////////////////
// RB0 D4
// RB1 D5
// RB2 D6
// RB3 D7
// RB4 RS
// RB5 E
// R/W ucu direkt þaseye baðlanacak

#define e   pin_d5 // LCD'nin E ucu RB5 pinine baðlý
#define rs  pin_d4 // LCD'nin RS ucu RB4 pinine baðlý

//****** LCD'ye Komut Gönderme Fonksiyonu **********
void lcd_komut(byte komut)
{
   output_d(komut>>4);  // Komutun yüksek deðerli 4 bitini gönder
   output_low(rs);       // LCD komut almak için ayarlandý
   output_high(e);       // E ucu lojik-1'den lojik-0'a çekiliyor
   output_low(e);
   delay_ms(2);         // 2 msn gecikme veriliyor

   output_d(komut&0x0F); // Komutun düþük deðerli 4 bitini gönder
   output_low(rs);       // LCD komut almak için ayarlandý
   output_high(e);        // E ucu lojik-1'den lojik-0'a çekiliyor
   output_low(e);
   delay_ms(2);        // 2 msn gecikme veriliyor
}
//******* LCD'ye Veri Gönderme Fonksiyonu **********
void lcd_veri(byte veri)
{
   if (veri=='Ç') veri=0; // Karakter Ç ise CGRAM 0.adresteki bilgiyi gönder
   if (veri=='Ð') veri=1; // Karakter Ð ise CGRAM 1.adresteki bilgiyi gönder
   if (veri=='Ý') veri=2; // Karakter Ý ise CGRAM 2.adresteki bilgiyi gönder
   if (veri=='Ö') veri=3; // Karakter Ö ise CGRAM 3.adresteki bilgiyi gönder
   if (veri=='Þ') veri=4; // Karakter Þ ise CGRAM 4.adresteki bilgiyi gönder
   if (veri=='Ü') veri=5; // Karakter Ü ise CGRAM 5.adresteki bilgiyi gönder
   if (veri=='I') veri=6; // Karakter I ise CGRAM 6.adresteki bilgiyi gönder
   if (veri==''') veri=7; // Karakter ' ise CGRAM 7.adresteki bilgiyi gönder

   output_d(veri>>4);   // Komutun yüksek deðerli 4 bitini gönder
   output_high(rs);       // LCD veri almak için ayarlandý
   output_high(e);       // E ucu lojik-1'den lojik-0'a çekiliyor
   output_low(e);
   delay_ms(1);       // 1 msn gecikme veriliyor

   output_d(veri&0x0F); // Komutun düþük deðerli 4 bitini gönder
   output_high(rs);     // LCD veri almak için ayarlandý
   output_high(e);      // E ucu lojik-1'den lojik-0'a çekiliyor
   output_low(e);
   delay_ms(1);         // 1 msn gecikme veriliyor
}

//******* LCD'de Ýmlec Konumlandýrma Fonksiyonu ********
void imlec(byte satir, byte sutun)
{
   if (satir==1)      // Eðer satýr deðiþkeni "1" ise
      lcd_komut(0x80|(sutun-1));

   if (satir==2)      // Eðer satýr deðiþkeni "2" ise
      lcd_komut(0x80|(0x40+(sutun-1)));
}

//********* LCD Baþlangýç Ayarlarý Fonksiyonu ******
void lcd_hazirla()
{
   lcd_komut(0x02);// LCD'yi kullanýma hazýr hale getir, imleç                // 1.satýr 1.sütunda komutu
   lcd_komut(0x28);//2 satýr, 4 bit iletiþim, 5x8 dot matris seçildi 
   lcd_komut(0x08);//Display kapalý,alt çizgi ve yanýp sönme yok
   lcd_komut(0x0C);//Display açýk,imleç alt çizgi ve yanýp sönme yok
   lcd_komut(0x06);// Her veri yazýldýðýnda imleç bir saða gitsin
   lcd_komut(0x01);// Display sil. Ýmleç 1.satýr 1.sütunda
   delay_ms(1);    // 1 msn bekle
}

//*** Özel Karakterleri CGRAM'e Yükleyen Fonksiyon ****
void ozel_karakterler()
{  
   // CGRAM'de 1. Adrese "Ç" Karakteri Kaydediliyor
   lcd_komut(0x40);lcd_veri(14);
   lcd_komut(0x41);lcd_veri(17);
   lcd_komut(0x42);lcd_veri(16);
   lcd_komut(0x43);lcd_veri(16);
   lcd_komut(0x44);lcd_veri(16);
   lcd_komut(0x45);lcd_veri(21);
   lcd_komut(0x46);lcd_veri(14);
   lcd_komut(0x47);lcd_veri(4);

   // CGRAM'de 1. Adrese "Ð" Karakteri Kaydediliyor
   lcd_komut(0x48);lcd_veri(14);
   lcd_komut(0x49);lcd_veri(0);
   lcd_komut(0x4A);lcd_veri(15);
   lcd_komut(0x4B);lcd_veri(16);
   lcd_komut(0x4C);lcd_veri(19);
   lcd_komut(0x4D);lcd_veri(17);
   lcd_komut(0x4E);lcd_veri(15);
   lcd_komut(0x4F);lcd_veri(0);

   // CGRAM'de 2. Adrese "Ý" Karakteri Kaydediliyor
   lcd_komut(0x50);lcd_veri(4);
   lcd_komut(0x51);lcd_veri(0);
   lcd_komut(0x52);lcd_veri(4);
   lcd_komut(0x53);lcd_veri(4);
   lcd_komut(0x54);lcd_veri(4);
   lcd_komut(0x55);lcd_veri(4);
   lcd_komut(0x56);lcd_veri(4);
   lcd_komut(0x57);lcd_veri(0);

   // CGRAM'de 3. Adrese "Ö" Karakteri Kaydediliyor
   lcd_komut(0x58);lcd_veri(10);
   lcd_komut(0x59);lcd_veri(0);
   lcd_komut(0x5A);lcd_veri(14);
   lcd_komut(0x5B);lcd_veri(17);
   lcd_komut(0x5C);lcd_veri(17);
   lcd_komut(0x5D);lcd_veri(17);
   lcd_komut(0x5E);lcd_veri(14);
   lcd_komut(0x5F);lcd_veri(0);

   // CGRAM'de 4. Adrese "Þ" Karakteri Kaydediliyor
   lcd_komut(0x60);lcd_veri(14);
   lcd_komut(0x61);lcd_veri(17);
   lcd_komut(0x62);lcd_veri(16);
   lcd_komut(0x63);lcd_veri(14);
   lcd_komut(0x64);lcd_veri(1);
   lcd_komut(0x65);lcd_veri(17);
   lcd_komut(0x66);lcd_veri(14);
   lcd_komut(0x67);lcd_veri(4);

   // CGRAM'de 5. Adrese "Ü" Karakteri Kaydediliyor
   lcd_komut(0x68);lcd_veri(10);
   lcd_komut(0x69);lcd_veri(0);
   lcd_komut(0x6A);lcd_veri(17);
   lcd_komut(0x6B);lcd_veri(17);
   lcd_komut(0x6C);lcd_veri(17);
   lcd_komut(0x6D);lcd_veri(17);
   lcd_komut(0x6E);lcd_veri(14);
   lcd_komut(0x6F);lcd_veri(0);

   // CGRAM'de 6. Adrese "I" Karakteri Kaydediliyor
   lcd_komut(0x70);lcd_veri(4);
   lcd_komut(0x71);lcd_veri(4);
   lcd_komut(0x72);lcd_veri(4);
   lcd_komut(0x73);lcd_veri(4);
   lcd_komut(0x74);lcd_veri(4);
   lcd_komut(0x75);lcd_veri(4);
   lcd_komut(0x76);lcd_veri(4);
   lcd_komut(0x77);lcd_veri(0);

   // CGRAM'de 7. Adrese "'" Karakteri Kaydediliyor
   lcd_komut(0x78);lcd_veri(12);
   lcd_komut(0x79);lcd_veri(18);
   lcd_komut(0x7A);lcd_veri(18);
   lcd_komut(0x7B);lcd_veri(12);
   lcd_komut(0x7C);lcd_veri(0);
   lcd_komut(0x7D);lcd_veri(0);
   lcd_komut(0x7E);lcd_veri(0);
   lcd_komut(0x7F);lcd_veri(0);
}
