/////////////////////////////////////////////////////////////////
//                    �zel_LCD.c                           //////
// Bu LCD s�r�c� dosyas� 2x16 HD44780 uyumlu LCD'ler        /////
// i�in yaz�lm��t�r. LCD'den sadece okuma yap�laca�� i�in   /////
// R/W ucu �aseye ba�lanmal�d�r. LCD ba�lant�s� a�a��dad�r. /////
// Bu LCD dosyas� ile �zel karakterler de LCD g�sterilebilinir //
/////////////////////////////////////////////////////////////////
// RB0 D4
// RB1 D5
// RB2 D6
// RB3 D7
// RB4 RS
// RB5 E
// R/W ucu direkt �aseye ba�lanacak

#define e   pin_d5 // LCD'nin E ucu RB5 pinine ba�l�
#define rs  pin_d4 // LCD'nin RS ucu RB4 pinine ba�l�

//****** LCD'ye Komut G�nderme Fonksiyonu **********
void lcd_komut(byte komut)
{
   output_d(komut>>4);  // Komutun y�ksek de�erli 4 bitini g�nder
   output_low(rs);       // LCD komut almak i�in ayarland�
   output_high(e);       // E ucu lojik-1'den lojik-0'a �ekiliyor
   output_low(e);
   delay_ms(2);         // 2 msn gecikme veriliyor

   output_d(komut&0x0F); // Komutun d���k de�erli 4 bitini g�nder
   output_low(rs);       // LCD komut almak i�in ayarland�
   output_high(e);        // E ucu lojik-1'den lojik-0'a �ekiliyor
   output_low(e);
   delay_ms(2);        // 2 msn gecikme veriliyor
}
//******* LCD'ye Veri G�nderme Fonksiyonu **********
void lcd_veri(byte veri)
{
   if (veri=='�') veri=0; // Karakter � ise CGRAM 0.adresteki bilgiyi g�nder
   if (veri=='�') veri=1; // Karakter � ise CGRAM 1.adresteki bilgiyi g�nder
   if (veri=='�') veri=2; // Karakter � ise CGRAM 2.adresteki bilgiyi g�nder
   if (veri=='�') veri=3; // Karakter � ise CGRAM 3.adresteki bilgiyi g�nder
   if (veri=='�') veri=4; // Karakter � ise CGRAM 4.adresteki bilgiyi g�nder
   if (veri=='�') veri=5; // Karakter � ise CGRAM 5.adresteki bilgiyi g�nder
   if (veri=='I') veri=6; // Karakter I ise CGRAM 6.adresteki bilgiyi g�nder
   if (veri==''') veri=7; // Karakter ' ise CGRAM 7.adresteki bilgiyi g�nder

   output_d(veri>>4);   // Komutun y�ksek de�erli 4 bitini g�nder
   output_high(rs);       // LCD veri almak i�in ayarland�
   output_high(e);       // E ucu lojik-1'den lojik-0'a �ekiliyor
   output_low(e);
   delay_ms(1);       // 1 msn gecikme veriliyor

   output_d(veri&0x0F); // Komutun d���k de�erli 4 bitini g�nder
   output_high(rs);     // LCD veri almak i�in ayarland�
   output_high(e);      // E ucu lojik-1'den lojik-0'a �ekiliyor
   output_low(e);
   delay_ms(1);         // 1 msn gecikme veriliyor
}

//******* LCD'de �mlec Konumland�rma Fonksiyonu ********
void imlec(byte satir, byte sutun)
{
   if (satir==1)      // E�er sat�r de�i�keni "1" ise
      lcd_komut(0x80|(sutun-1));

   if (satir==2)      // E�er sat�r de�i�keni "2" ise
      lcd_komut(0x80|(0x40+(sutun-1)));
}

//********* LCD Ba�lang�� Ayarlar� Fonksiyonu ******
void lcd_hazirla()
{
   lcd_komut(0x02);// LCD'yi kullan�ma haz�r hale getir, imle�                // 1.sat�r 1.s�tunda komutu
   lcd_komut(0x28);//2 sat�r, 4 bit ileti�im, 5x8 dot matris se�ildi 
   lcd_komut(0x08);//Display kapal�,alt �izgi ve yan�p s�nme yok
   lcd_komut(0x0C);//Display a��k,imle� alt �izgi ve yan�p s�nme yok
   lcd_komut(0x06);// Her veri yaz�ld���nda imle� bir sa�a gitsin
   lcd_komut(0x01);// Display sil. �mle� 1.sat�r 1.s�tunda
   delay_ms(1);    // 1 msn bekle
}

//*** �zel Karakterleri CGRAM'e Y�kleyen Fonksiyon ****
void ozel_karakterler()
{  
   // CGRAM'de 1. Adrese "�" Karakteri Kaydediliyor
   lcd_komut(0x40);lcd_veri(14);
   lcd_komut(0x41);lcd_veri(17);
   lcd_komut(0x42);lcd_veri(16);
   lcd_komut(0x43);lcd_veri(16);
   lcd_komut(0x44);lcd_veri(16);
   lcd_komut(0x45);lcd_veri(21);
   lcd_komut(0x46);lcd_veri(14);
   lcd_komut(0x47);lcd_veri(4);

   // CGRAM'de 1. Adrese "�" Karakteri Kaydediliyor
   lcd_komut(0x48);lcd_veri(14);
   lcd_komut(0x49);lcd_veri(0);
   lcd_komut(0x4A);lcd_veri(15);
   lcd_komut(0x4B);lcd_veri(16);
   lcd_komut(0x4C);lcd_veri(19);
   lcd_komut(0x4D);lcd_veri(17);
   lcd_komut(0x4E);lcd_veri(15);
   lcd_komut(0x4F);lcd_veri(0);

   // CGRAM'de 2. Adrese "�" Karakteri Kaydediliyor
   lcd_komut(0x50);lcd_veri(4);
   lcd_komut(0x51);lcd_veri(0);
   lcd_komut(0x52);lcd_veri(4);
   lcd_komut(0x53);lcd_veri(4);
   lcd_komut(0x54);lcd_veri(4);
   lcd_komut(0x55);lcd_veri(4);
   lcd_komut(0x56);lcd_veri(4);
   lcd_komut(0x57);lcd_veri(0);

   // CGRAM'de 3. Adrese "�" Karakteri Kaydediliyor
   lcd_komut(0x58);lcd_veri(10);
   lcd_komut(0x59);lcd_veri(0);
   lcd_komut(0x5A);lcd_veri(14);
   lcd_komut(0x5B);lcd_veri(17);
   lcd_komut(0x5C);lcd_veri(17);
   lcd_komut(0x5D);lcd_veri(17);
   lcd_komut(0x5E);lcd_veri(14);
   lcd_komut(0x5F);lcd_veri(0);

   // CGRAM'de 4. Adrese "�" Karakteri Kaydediliyor
   lcd_komut(0x60);lcd_veri(14);
   lcd_komut(0x61);lcd_veri(17);
   lcd_komut(0x62);lcd_veri(16);
   lcd_komut(0x63);lcd_veri(14);
   lcd_komut(0x64);lcd_veri(1);
   lcd_komut(0x65);lcd_veri(17);
   lcd_komut(0x66);lcd_veri(14);
   lcd_komut(0x67);lcd_veri(4);

   // CGRAM'de 5. Adrese "�" Karakteri Kaydediliyor
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
