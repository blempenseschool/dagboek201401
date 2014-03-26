# Project Dagboek

1. [Inleiding](#inleiding)
2. [Login systeem](#login-systeem)
3. [Flash messages](#flash-messages)
4. [Back-end - CRUD systeem](#back-end---crud-systeem)
5. [Front-end](#front-end)
6. [Extra's](#extras)

## Inleiding

Dit project moet een simpel online dagboek worden. Gebruikers kunnen zich registreren voor een eigen dagboek. Ze kunnen dan openbare en private dagboek berichten aanmaken. De andere gebruikers kunnen doormiddel van de username zoeken naar andere gebruikers en zo hun dagboek avonturen volgen. 

Er moeten een hele boel taken nog toegevoegd worden aan dit project. Elk groepje wordt telkens een taak toegewezen. Deze taak moet elk groepje zo goed mogelijk tot een einde proberen te brengen. Indien de tijd erop zit zal de code gecommit en gepushed moeten worden naar deze server. 

Dan kan elk groepje de code terug downloaden zodat iedereen terug "up to date" is. Er worden nieuwe taken aan elk groepje aangeduid en zij zullen moeten verderwerken op de code van de vorige groep. Ze moeten proberen de code te verbeteren of eventuele fouten eruit te halen.
 
Uiteindelijk zal deze code gepushed worden naar een webserver en moeten we dan tot een werkend geheel komen.

**Databank configuratie**: In het *includes* mapje kan je een bestand *dbConfig.default.inc.php* terug vinden. Dit bestand moet je dupliceren en hernoemen naar *dbConfig.inc.php*. Hierin kan je dan jouw databank gegevens invullen.

## Taken

Elk groepje zal enkele taken aangewezen krijgen. Probeer niet onmiddelijk te programmeren maar denk eerst even na over wat er moet gebeuren en hoe je dit zou kunnen vertalen naar PHP. Begin met commentaar code te schrijven die beschrijft wat de code moet doen. Vertaal deze commentaar code dan stap voor stap naar PHP code. Zorg ook dat je elke stap voldoende documenteert adhv commentaar zodat de volgende groep snel jouw code kan begrijpen en hierop kan verderwerken.

**Hier volgen de verschillende taken die uitgevoerd moeten worden:**

### Login systeem

Het login systeem maakt gebruik van de *$_SESSION[]* variabele van PHP. Deze variabele is een array die we over meerdere pagina's heen kunnen gebruiken. Het enige dat we moeten doen is op elke pagina bovenaan, als eerste regel code, de functie *session_start()* plaatsen.

- **Paswoord beveiliging dmv van de CRYPT functie van PHP** - registreer.php

  Nu worden de paswoorden als "plain text" in de databank opgeslaan. Het is beter om deze paswoorden te verbergen. Daarom gaan we ze encrypteren met een speciaal algoritme. Dit moeten we dus doen voordat we de paswoorden in de databank steken, dus bij de *registratie* van de gebruiker.

- **Login gegevens controleren** - login.php

  Bij het verzenden van het login formulieren moeten we eerst *valideren* dat de velden die verstuurd worden niet leeg zijn. Dan moeten we in de databank de gegevens van het gegeven emailadres gaan opzoeken. Indien we deze gegevens gevonden hebben moeten we controleren of het paswoord dat we in het formulier ontvangen overeenkomt met het paswoord in de databank. Indien dat zo is kunnen we de gebruiker inloggen dmv van een *$_SESSION['user']* variabele. Als een gebruiker succesvol ingelogd is moet hij doorverwezen worden naar de *pagina-toevoegen.php* pagina.

### Flash messages

We gaan het "geheugen" van PHP niet enkel gebruiken om gegevens van de ingelogde gebruiker te onthouden, maar we kunnen het geheugen ook gebruiken om berichten door te sturen naar de volgende pagina. Zo kunnen we ,bv. als het toevoegen van een pagina gelukt is, een bericht sturen naar de volgende pagina en aan de gebruiker een melding tonen dat het toevoegen gelukt is. Normaal gezien kan je in PHP enkel op dezelfde pagina jouw foutmeldingen of berichten tonen. Op deze manier kunnen we flexibeler omgaan met deze berichten.

- **Een functie aanmaken om een bericht te versturen** - flashAlert($tekst, $type)

  Om het ons gemakkelijk te maken gaan we een functie aanmaken waarin we een bericht kunnen versturen naar de volgende pagina. We geven de tekst en het type van het bericht mee. Deze berichten worden in een *$_SESSION['flash']* variabele bijgehouden. De array die we hieraan meegeven bestaat uit een variabele *tekst* en een variabele *type*.

- **Een functie aanmaken om berichten te tonen** - toonFlashAlerts()

  Naast het versturen van de alert maken we ook een functie die het ons gemakkelijk maakt om de HTML van de alert te tonen. Deze functie voegen we dan ook toe op elke pagina.

- **Een functie aanmaken om het doorsturen naar andere pagina's gemakkelijker te maken** - redirect_naar($to, $tekst, $type) 

  Deze functie zal het gemakkelijker maken voor ons om gebruikers door te sturen naar andere pagina's. Zo hoeven we niet telkens gebruik te maken van de header('location:') functie. We maken de functie op zo'n manier dat we er een alert aan kunnen koppelen die we op de volgende pagina kunnen tonen.

### Back-end - CRUD systeem

Nu de login functionaliteit en flash messages werken kunnen we beginnen aan de CRUD functionaliteit van onze website. We moeten het mogelijk maken voor onze gebruikers om nieuwe pagina's toe te voegen in hun dagboek. Maar ze moeten ook de mogelijkheid hebben om bestaande pagina's aan te passen en te verwijderen. 

- **Nieuwe pagina's toevoegen** - pagina-toevoegen.php

  Voor deze pagina zullen we eerst **formulier validatie** moeten toevoegen. Deze validatie plaatsen we ook in een nieuwe bestand zodat we dit gemakkelijk op andere pagina's ook kunnen inladen. De *titel* en de *inhoud* zijn **verplicht**. Zorg er ook voor dat alle inhouden terug ingevuld worden in het formulier, en dat de foutmeldingen getoont worden. Denk ook aan de 'has-error' css klasse die toegevoegd moet worden indien er een foutmelding bestaat voor het formulierelement.

  Dan moeten we gegevens toevoegen aan de databank. Dit doen we met een *prepared query* van PDO. Je moet ook de userID van de ingelogde gebruiker meegeven aan de query. Indien het toevoegen gelukt is ga je de gebruiker, met een bericht, doorsturen naar *pagina-bekijken.php*. Indien het niet gelukt is maak je een *flashAlert* aan en toon je dezelfde pagina opnieuw met een foutmelding dat de gebruiker opnieuw moet proberen.

- **Pagina's weergeven** - pagina-bekijken.php

- **Pagina's aanpassen** - pagina-aanpassen.php

- **Pagina's verwijderen** - pagina-verwijderen.php

- **Dagboek beheren** - dagboek-beheren.php

### Front-end

Nu we de back-end van de website achter de rug hebben, kunnen we aan de slag met de front-end. Deze pagina's kunnen ook niet-ingelogde gebruikers bekijken.

- **Dagboek bekijken**: dagboek.php

- **Nieuwste pagina's van alle dagboeken**: nieuwe-paginas.php

- **Paginatie toevoegen aan pagina's**: dagboek.php, nieuwe-paginas.php (en dagboek-beheren.php)

### Extra's

Nu onze website bijna klaar is kunnen we nog nieuwe functionaliteit gaan toevoegen. 

- **Het gebruik van Markdown**

- **De index pagina**

- **Gebruiker onmiddelijk inloggen na registratie**

- **Gebruikers zoeken**