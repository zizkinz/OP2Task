# Versija V0.1:
*  Sukūrta struktūra "Studentas", kurioje yra laikomi studentu vardai, pavardės; namų darbų, bei egzamino įvertinimai, galutinis studento balas.
*  Implementuotas "rankinis" duomenų įvedimo būdas, bei duomenų atsitiktinis generavimas .
*  Implementuotas galutinio balo skaičiavimo algoritmas naudojant medianą, arba vidurkį.
*  Sukūrta "gražiaus" studentų duomenų išvedimo funkcija.

Sąrašai implementuoti dviem būdais:

* Faile *main.cpp* nauduojant tik ***std::vector***.

* Faile *DynamicArray.cpp* naudojant tik ***dinaminius masyvus***.

# Versija V0.2:

* Implementuotas duomenų nuskaitymas iš failo.
* Yra sukūrtas pavyzdinis *kursiokai.txt* failas su 24-ių studentų duomenimis;
* Prieš išvedant rezultatus, studentai yra surušiojami pagal vardą ir pavardę.
* Rezultatuose dabar galutinis balas yra skaičiuojamas ir pagal medianą, ir pagal vidurkį.

***Nuo šios versijos visi sąrašai yra implementuoti tik naudojant std::vector konteinerius.***

# Versija V0.3:

* Padarytas kodo refactoring'as: struktūros ir funkcojos yra perkelti į jiems atitinkamus header ir source failus.
* Imprelentuotas exception handling. Dabar atidarant failą, jo egzistavimo patikra panaudoja išimčių valdymą.

# Versija V0.4:

* Implementuotas automatinis *1000, 10 000, 100 000, 1000 000, 10 000 000* įrašų failų generavimas.
* Implementuotas studentų sąrašo rušiavimas pagal gautinį balą.
* Implementuotas surušiuoto studentų sąrašo suskirstymas į du failus (kur galutinis < 5 ir kur galutinis => 5).
* Surūšiuoti studentų sąrašai yra išvedami į du atitinkamus failus.

***Atlikta programos veikimo greičio analizė naudojant C++ chrono biblioteką:***

![alt text](https://github.com/zizkinz/OP1Task/blob/af17400fa26c2ed5fd80eb4dfbbf3122941e9e6d/tests.png?raw=true)

**Atlikus 4 testus, buvo gauti tokie suvidurkinti rezultatai:**


|Įrašų skaičius|Vidutinis testų laikas|Laiko augimas, padidinus įrašų sk. 10 kartų|
|---:|:---:|:---:|
|1 000|0.02154835 s.|100 %|
|10 000|0.1459253 s.|677 %|
|100 000|1.39388 s.|955 %|
|1 000 000|13.88358 s.|996 %|
|10 000 000|148.7353 s.|1071 %|

**Taigi, programos veikimo greitis auga maždaug tiesiškiai, didinant įrašų skaičių**

# Versija V0.5:

* Padaryti testai su vector ir list tipo sąrašais

![alt text](https://github.com/zizkinz/OP1Task/blob/af17400fa26c2ed5fd80eb4dfbbf3122941e9e6d/test2.png?raw=true)

**Gauti rezultatai:**





* Įrašų nuskaitymo laikas visais atvėjais buvo mažesnis naudojant _**list'ą**_.

* Įrašų rūšiavimo laikas visais atvėjais buvo mažesnis naudojant _**vector'ių**_.

* Bendras testo laikas buvo mažesnis naudojant _**list**_, kai irašų buvo nedaugiau už 100 000. 
Testuojant 10 000 000 įrašų,  _**vector**_ jau pasirode geriau, negu _**list**_.

***Sistema, kurioje buvo atlikti testai:***


|CPU|RAM|Drive|
|---|---|---|
|Apple M1 3.2 GHz|8 GB LPDDR4X|NVMe SSD|


# Versija V1.0:

* Padaryti skirtingų algortimtų ir rušavimo strategijų greitaveikos testai.

***išvada:***

*Geriausiai šiam uždaviniui tinka vector duomenų saugojimo tipas kartu su dviejų naujų konteinerių strategija*


![alt text](https://github.com/zizkinz/OP1Task/blob/14ec3eb0cf18ae58f65eca4dac7e646d40fa412f/test3.png?raw=true)


# Naudojimosi instrukcija:

1) Panaudojus "CMakeLists.txt" failą, įdiekite programą.

2) Vykdomojo failo direktorijoje įdėkite testinius failus su pavadinimais

    "1000.txt", "10000.txt", ..., "10000000.txt" ir struktūra:
    
    Vardas Pavardė ND1 ... NDn Egzaminas.
3) Paleiskite programą.

