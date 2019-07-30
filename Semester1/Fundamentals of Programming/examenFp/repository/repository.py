from domain.entitati import Traducere


class RepoError(Exception):
    pass


class Repository():
    
    def __init__(self, numeFisier):
        '''
        initializarea cu numele fisierului
        '''
        self.numeFisier = numeFisier


    def iauDinFisier(self):
        '''
        functie ce imi ia traducerile din fiser
        '''
        
        try:
            fisier = open(self.numeFisier)
        except IOError:
            print("Nu s a deschis")
            return
        
        traduceri = []
        
        linie = fisier.readline().strip()
        while linie != "":
            
            delimitator = linie.split(",")
            traducere = Traducere(delimitator[0], delimitator[1], delimitator[2], delimitator[3])
            traduceri.append(traducere)
            linie = fisier.readline().strip()
        
        return traduceri
    
    def getTraduceri(self):
        return self.iauDinFisier()
    

    def store(self, traduceri):
        '''
        functie ce imi pune traducerile in fisier
        '''
        
        with open(self.numeFisier,"w") as fisier:
            for traducere in traduceri:
                text = ""
                text += traducere.getLimbaSursa()
                text += ","
                text += traducere.getCuvant()
                text += ","
                text += traducere.getLimbaDestinatie()
                text += ","
                text += traducere.getTraducereCuvant()
                text += "\n"
                fisier.write(text)
    
    
    def adaugaTraducere(self, traducere):
        '''
        functie ce adauga o traducere
        '''
        
        traduceri = self.getTraduceri()
        for traducereCuvant in traduceri:
            if traducereCuvant.getLimbaSursa() == traducere.getLimbaSursa() and traducere.getCuvant() == traducereCuvant.getCuvant() and traducere.getLimbaDestinatie()== traducereCuvant.getLimbaDestinatie():
                raise RepoError
        traduceri.append(traducere)
        self.store(traduceri)
        
        
    def cateTraduceri(self):
        '''
        functie ce returneaza numarul de traduceri
        '''
        return len(self.getTraduceri())
        
    
    
    
    
    
    
    
    
    
    
    