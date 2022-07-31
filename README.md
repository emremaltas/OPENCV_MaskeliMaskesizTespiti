# Maskeli - Maskesiz Yüz Tespiti

### Biyomedikal Mühendisliği 3. sınıf ***Mühendislik Tasarımı*** dersim için  kodlanmıştır.

<br/>

- Yazılım ağız, burun, yüz tespitine dayalı olarak insanın yüzünde maske olma durumu tespiti yapmaktadır.

<br/>

- Yüz tespiti işlemi için [maskeFoto](https://github.com/emremaltas/OPENCV_MaskeliMaskesizTespiti/tree/main/maskeFoto/maskeFoto) klasörü içindeki ***haarcascade_frontalface_default.xml*** dosyası kullanılmıştır.

<br/>

- Burun tespiti işlemi için [maskeFoto](https://github.com/emremaltas/OPENCV_MaskeliMaskesizTespiti/tree/main/maskeFoto/maskeFoto) klasörü içindeki ***haarcascade_mcs_nose.xml*** dosyası kullanılmıştır.

<br/>

- Ağız tespiti işlemi için [maskeFoto](https://github.com/emremaltas/OPENCV_MaskeliMaskesizTespiti/tree/main/maskeFoto/maskeFoto) klasörü içindeki ***haarcascade_mcs_mouth.xml*** dosyası kullanılmıştır.

# Algoritma

- Maske tespiti için öncelikle yüz tespitinin olup olmadığı kontrol edilmiştir.Ardından yüz tespiti var ise bu tespit edilen yüz dikdörtgen içine alınarak içinde  ağız ve burun araması gerçekleştiriliyor. Ağız veya burun  tespit edilirse ekrana ***"Maske Takili Değil"*** her ikiside tespit edilemez ise  ***"Maske Takili"*** yazılıyor.

- Maskesiz yüz tespit edildiğinde, masaüstüne oluşturulmuş ***maskesiz girenler*** klasörüne, yüzün fotoğrafı çekilerek kaydedilmektedir.


<br/>

# Çalışma Anına Ait Görseller

![Maske Takili Değil](https://github.com/emremaltas/OPENCV_MaskeliMaskesizTespiti/blob/main/maske%20takili%20değil.png)

<br/>

![Maske Takili](https://github.com/emremaltas/OPENCV_MaskeliMaskesizTespiti/blob/main/maske%20takili.png)

<br/>

![Maskesiz Girenler Klasörü](https://github.com/emremaltas/OPENCV_MaskeliMaskesizTespiti/blob/main/maskesiz%20girenler.png)





