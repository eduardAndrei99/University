from domain.entitati import Traducere
from repository.repository import Repository, RepoError
from domain.validator import ValidatorTraducere, ExceptieTraducere
from controller.utils import golescFisier
class Service():
    
    def __init__(self, validator, repository):
        '''
        service comunica cu validator si repository
        '''
        self.validator = validator
        self.repository = repository


    def getTraduceri(self):
        '''
        functie ce imi ia traducerile din fisier
        '''
        return self.repository.getTraduceri()
    
    
    def adaugaTraducere(self,limbaDestinatie, cuvant, limbaSursa, traducereCuvant):
        '''
        functie ce imi adauga o traducere
        '''
        
        traducere = Traducere(limbaDestinatie, cuvant, limbaSursa, traducereCuvant)
        self.validator.validate(traducere)
        self.repository.adaugaTraducere(traducere)
        return traducere
    
    def vizualizareTraduceri(self, limba):
        '''
        :param limba: limba sursa
        functia returneaza traducerile sortate din limba "limba" in celelalte
        '''
        
        traduceri = []
        for traducere in self.getTraduceri():
            if traducere.getLimbaSursa() == limba:
                traduceri.append(traducere)
        traduceri = sorted(traduceri, key = lambda x:x.getCuvant(), reverse = False)
        return traduceri
    
    
    def traducereText(self, fisierIntrare,limbaText,limbaDeTradus,fisierIesire):
        '''
        functie ce imi traduce textul
        '''
        
        fisier1 = open(fisierIntrare,"r")
        fisier2 = open(fisierIesire, "w")
        limbi = ["Ro", "En","Fr"]
        if limbaText not in limbi or limbaDeTradus not in limbi:
            raise ExceptieTraducere("")
        
        text = ""
        traduceri = self.getTraduceri()
        linie = fisier1.readline()
        while linie != "":
            delimitator = linie.split(",")
            for i in range(0, len(delimitator)):
                cuvant = delimitator[i]
                ok = False
                for traducere in traduceri:
                    if traducere.getLimbaSursa() == limbaText and traducere.getLimbaDestinatie() == limbaDeTradus:
                        if traducere.getCuvant() == cuvant:
                            text += traducere.getTraducereCuvant()
                            text += " "
                            ok = True
                    if traducere.getLimbaDestinatie() == limbaText and traducere.getLimbaSursa() == limbaDeTradus:
                        if traducere.getTraducereCuvant() == cuvant:
                            text += traducere.getCuvant()
                            text += " "
                            ok = True
                if ok == False:
                    text += "{"
                    text += cuvant
                    text += "} "
                    
            linie = fisier1.readline() 
  
        fisier2.write(text)
                            
    
        
def testAdaugaTraducere():
    '''
    functie ce testeaza adaugarea unei traduceri
    (cerinta 1)
    '''
    golescFisier("testServiceTraduceri.txt")
    repository = Repository("testServiceTraduceri.txt")
    validator = ValidatorTraducere()
    service = Service(validator, repository)
    '''
    Cazul in care merge:
    '''
    try:
        service.adaugaTraducere("Ro","pisica","En","cat")
        assert True
    except ExceptieTraducere:
        assert False
    except RepoError:
        assert False
    '''
    cazul in care nu e introdus bine:
    '''
    try:
        service.adaugaTraducere("romanda","dsadsa","dsadsada","Dsadsa")
        assert False
    except ExceptieTraducere:
        assert True
    except RepoError:
        assert False
    assert repository.cateTraduceri() == 1
    '''
    cazul in care mai exista o traducere a cuvantului
    '''
    try:
        service.adaugaTraducere("Ro","pisica","En","dog")
        assert False
    except ExceptieTraducere:
        assert False
    except RepoError:
        assert True
    
        
testAdaugaTraducere()
    
    
    
    
    
    
    
            
        
        

        
            
    