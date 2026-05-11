# Pac-Man 🕹️ (C++/SFML)
Klasyczna implementacja gry Pac-Man stworzona w języku C++ z wykorzystaniem biblioteki multimedialnej SFML. Projekt skupia się na czystej architekturze obiektowej i logice poruszania się w labiryncie.

## 🛠️ Kluczowe rozwiązania techniczne
- **Obiektowa Architektura (OOP):** Pełna separacja logiki gry, zarządzania mapą oraz zachowań przeciwników (klasy Ghost, Map, Game).
- **Algorytmika poruszania:** Implementacja logiki kolizji w siatce kafelkowej (Tile Map) oraz systemu punktów (klasa Point).
- **Zarządzanie zasobami:** Efektywne ładowanie i zarządzanie teksturami oraz obsługą zdarzeń w czasie rzeczywistym (SFML Event Loop).
- **Mechanika AI:** Podstawowe algorytmy losowego poruszania się duchów, reagujące na strukturę labiryntu.
- **Zarządzanie kontenerami (STL):** Efektywne wykorzystanie kontenerów biblioteki standardowej (np. std::vector) do zarządzania dynamicznymi obiektami w grze, takimi jak duchy czy punkty na mapie.
- **Grafika generatywna (Procedural Rendering):** Całość oprawy wizualnej gry została zrealizowana bez użycia zewnętrznych plików graficznych. Labirynt, postać Pac-Mana oraz duchy są generowane dynamicznie za pomocą prymitywów biblioteki SFML (RectangleShape, CircleShape), co optymalizuje wydajność i upraszcza strukturę projektu.

## ✨ Funkcjonalności
- Dynamicznie generowany labirynt na podstawie tablicy kafli.
- System zbierania punktów i licznik wyniku.
- Różne, losowe zachowania duchów.
- Płynne sterowanie klawiaturą (WASD).

## 🚀 Jak uruchomić?
1. Upewnij się, że masz zainstalowaną bibliotekę SFML 2.5.x/2.6.x.
2. Skonfiguruj linker dla bibliotek SFML (sfml-graphics, sfml-window, sfml-system).
3. Skompiluj projekt za pomocą kompilatora C++ (np. MinGW lub MSVC).

## 📝 Symulacja korzystania (krok po kroku)

Aplikacja przenosi klasyczną mechanikę arcade do środowiska C++. Oto jak przebiega rozgrywka:

**1. Menu Startowe**

Po uruchomieniu użytkownika wita ekran tytułowy. Z poziomu menu można rozpocząć nową grę lub zapoznać się z zasadami. Już tutaj widać wykorzystanie prymitywów SFML do stworzenia czytelnego interfejsu.

---

**2. Rozpoczęcie rozgrywki**

Gracz przejmuje kontrolę nad Pac-Manem w labiryncie generowanym proceduralnie z tablicy kafli.

Sterowanie odbywa się za pomocą klawiatury (WASD).

Zadaniem gracza jest zebranie wszystkich punktów rozmieszczonych w korytarzach.

---

**3. Mechanika przeciwników i kolizji**

W trakcie gry na mapie pojawiają się duchy.

- **AI Duchów:**
Przeciwnicy poruszają się po labiryncie, reagując na układ ścian.
- **System Kolizji:**
Program w czasie rzeczywistym przelicza współrzędne Pac-Mana względem siatki labiryntu, obsługując zbieranie punktów oraz kontakt z przeciwnikiem.

---

**4. Koniec gry i wynik**

Gra kończy się w momencie kontaktu z duchem lub zebrania wszystkich punktów. System wyświetla końcowy komunikat, informując gracza o wyniku.

---

*Projekt stworzony na potrzeby zaliczenia przedmiotu na studiach w roku akademickim 2024/2025.*

*Indywidualna praca Joanny Czeluśniak*
