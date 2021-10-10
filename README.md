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

