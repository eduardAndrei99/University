from utils.utils import citesteNumar
from domain.validator import ExceptieJucator
from repository import RepoError
class Consola():
    
    def __init__(self, service):
        self.service = service
        
        
    def printMeniu(self):
        
        print("1 -> Adauga jucator")
        print("2 -> Modifica inaltime")
        print("3 -> Tipareste echipa")
        print("4 -> Importa jucatori")
        print("5 -> Afiseaza din fisier")


    def adaugaJucator(self):
        nume = input("Introduceti numele >> ")
        prenume = input("Introduceti prenumele >> ")
        inaltime = citesteNumar()
        post = input("Introduceti postul >> ")
        try:
            self.service.adaugaJucator(nume, prenume, inaltime, post)
        except ExceptieJucator as ex:
            print(str(ex))
    
    
    def afiseazaJucatori(self):
        totiJucatorii = self.service.getJucatori()
        for jucator in totiJucatorii:
            print(str(jucator))
    
    
    def modificaInaltime(self):
        nume = input("Introduceti numele >> ")
        prenume = input("Introduceti prenumele >> ")
        inaltime = citesteNumar()
        try:
            self.service.modificaInaltime(nume, prenume, inaltime)
        except RepoError as ex:
            print("Jucatoru nu exista")
    
    
    def facEchipa(self):
        pivoti = self.service.getPivoti()
        fundasi = self.service.getFundasi()
        extreme = self.service.getExtreme()
        echipa = self.service.facEchipa(fundasi,pivoti,extreme)
        for jucator in echipa:
            print(str(jucator))
        
        
    
    def importaJucatori(self):
        numeFisier = input("Nume fisier >>")
        jucatoriImportati = self.service.importaJucatori(numeFisier)
        print(jucatoriImportati)
    
    
    def showUi(self):
        while True:
            self.printMeniu()
            comanda = input(">>")
            if comanda == "1":
                self.adaugaJucator()
            if comanda == "2":
                self.modificaInaltime()
            if comanda == "5":
                self.afiseazaJucatori()    
            if comanda == "3":
                self.facEchipa()
            if comanda == "4":
                self.importaJucatori()
            
            
            
            
            
            
