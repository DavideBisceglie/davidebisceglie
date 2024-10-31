# calendario.py

import random

class Calendario:
    def __init__(self, squadre):
        if len(squadre) != 20:
            raise ValueError("Il numero di squadre deve essere 20.")
        self.squadre = squadre
        self.partite = []

    def genera_calendario(self):
        # Genera tutte le combinazioni possibili di partite (andata e ritorno)
        andata = [(casa, trasferta) for i, casa in enumerate(self.squadre) for trasferta in self.squadre[i + 1:]]
        ritorno = [(trasferta, casa) for casa, trasferta in andata]

        # Combina le partite di andata e ritorno e mescola
        self.partite = andata + ritorno
        random.shuffle(self.partite)

        # Dividi le partite in 38 giornate
        giornate = [self.partite[i:i + 10] for i in range(0, len(self.partite), 10)]
        return giornate

    def mostra_calendario(self):
        giornate = self.genera_calendario()
        for i, giornata in enumerate(giornate, 1):
            print(f"\nGiornata {i}")
            for casa, trasferta in giornata:
                print(f"{casa} vs {trasferta}")

if __name__ == "__main__":
    # Elenco delle 20 squadre (inserisci i nomi delle squadre che preferisci)
    squadre = [
        "Squadra1", "Squadra2", "Squadra3", "Squadra4", "Squadra5",
        "Squadra6", "Squadra7", "Squadra8", "Squadra9", "Squadra10",
        "Squadra11", "Squadra12", "Squadra13", "Squadra14", "Squadra15",
        "Squadra16", "Squadra17", "Squadra18", "Squadra19", "Squadra20"
    ]

    # Crea il calendario e genera le giornate
    calendario = Calendario(squadre)
    print("Genera il calendario completo di 38 giornate:\n")
    calendario.mostra_calendario()