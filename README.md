# Tema-2-POO-12
Se dau clasele:
- Card(string nrCard, string NumeDetinator, string data_expirare, int CVV, double credit)
- Card_Standard (int limitaExtragere, double comisionDepasireLimita): Card
- Card_premium (double cashback): Card_Standard
  - Sa permiteti printr-o metoda sa extrageti bani de pe un card. Sa se verifice ca aceasta suma sa nu fie mai mare decat creditul. Sa se modifice creditul la extragere in functie de cad standard sau premium. Daca depaseste limita cardului standard atunci se aplica comisionul pentru diferenta de bani. Daca se extrage de pe un card premium sa primeasca inapoi cashback/100 * suma extrasa
