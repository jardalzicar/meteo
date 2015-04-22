# Školní meteorologická stanice

Jednoduchá meteorologická stanice založená na platformě [arduino](http://www.arduino.cc), která měří teplotu, tlak a vlhkost vzduchu, tato data ukládá do databáze a následně zobrazuje přes webovou aplikaci.

- **Aktuální verze:** <http://gjk.cz/~xlzij01/meteo/>
- **Ukázka:** [screenshoty](https://github.com/jardalzicar/meteo/tree/master/screenshots)
- **Dokumentace:** [dokumentace projektu v pdf](http://abc) 
- **Repozitář:** [jardalzicar/meteo](https://github.com/jardalzicar/meteo) + [fork](https://github.com/gjkcz/meteo) v archivu maturitních prací
- **Autor:** Jaroslav Lžičař, <jarda.lzicar@seznam.cz>
- **Maturitní práce 2014/15** na [GJK](https://github.com/gjkcz/gjkcz)


## Dokumentace pro uživatele


####Aplikaci spustíte kliknutím na [tento odkaz](http://gjk.cz/~xlzij01/meteo/)  
Po načtení by měla stránka vypadat následovně  
![Alt text](screenshots/gui0.png =x500)

### Ovládání

V horní části stránky vidíte aktuální hodnoty teploty, tlaku vlhkosti vzduchu, rosného bodu a pocitové teploty (zobrazuje se pouze při teplotě vyšší než 25 °C).
První graf zobrazuje vývoj teploty (zelená plocha) a tlaku (černá čára) za poslední 3 dny.  
 
![Alt text](screenshots/chart1.png =x250)  
  
V levém horním rohu lze vybrat požadovaný rozsah grafu, maximální hodnota je 1 týden.  
  
![Alt text](screenshots/range_selector.png =300x)  

Pro přesnější výběr je možno použít posuvník pod grafem.  

![Alt text](screenshots/navigator.png =300x)  

V pravém horním rohu grafu si můžete vybrat, které data budou zobrazena.  

![Alt text](screenshots/series.png =300x)  



## Dokumentace pro programátory
(Chci si něco upravit a používat, nebo třeba opravit chybu a poslat pull-request.)

### Kompilace 
(Pro některé projekty vhodnější nazvat např. Příprava dev režimu)

Pokud uživatel nechce binárku, ale chce si zkompilovat zdrojáky. Stáhne je z githubu a co dál - otevřít v IDE (verze), nastaví kompilátor (odkaz na stažení konkrétní verze), dá build. Nebo třeba zadá `make` a vše se stane samo

### Struktura kódu
Základní orientace v kódu, jaké jsou hlavní části (sql-model.php), rozmístění složek, 

...

Podrobnější návod je vhodné odkázat do dokumentačního PDFka - s popisem co tam třeba lze najít (popis tříd, atd)


## (Changelog)
(Původní changelog dejte třeba do changelog.md, či úplně smažte. Sem patří jedině changlog po releasech, jinak nic a sekci nevkládat.)

## Screenshoty, obrázky
(Obrázek vydá za tisíc bajtů. Aspoň dva.)