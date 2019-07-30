from domain.entitate import Jucator
from utils.utils import golescFisier

class RepoError(Exception):
    pass


class repositoryFisiere():
    
    def __init__(self, numeFisier):
        '''
        numele fisirului:
        :param numeFisier:
        '''
        self.numeFisier = numeFisier


    def iauDinFisier(self):
        '''
        iau jucatorii din fisier splituiti dupa ,
        '''
        try:
            fisier = open(self.numeFisier)
        except IOError as ex:
            print("Fisierul nu a fost deschis")
            return
        
        linie = fisier.readline().strip()
        jucatori = []
        while linie != "":
            
            delimitator = linie.split(",")
            jucator = Jucator(delimitator[0], delimitator[1], delimitator[2], delimitator[3])
            jucatori.append(jucator)
            linie = fisier.readline().strip()
            
        return jucatori
         
    def getJucatori(self):
        '''
        iau toti jucatorii din fisier cu ajutorul functiei de mai sus
        '''
        return self.iauDinFisier()
    
    def store(self, totiJucatorii):
        
        with open(self.numeFisier, "w") as fisier:
            for jucator in totiJucatorii:
                fisier.write(jucator.getNume() + ',' + jucator.getPrenume() + ',' +str(jucator.getInaltime())+ ','+jucator.getPost())
                fisier.write("\n")
            
    
    def adaugaJucator(self, jucator):
        '''
        adaug un jucator in fisier
        :param jucator: jucatorul de adaugat
        '''
        totiJucatorii = self.getJucatori()
        totiJucatorii.append(jucator)
        self.store(totiJucatorii)
        
    def modificaInaltime(self, nume,prenume, inaltime):
        ok = False
        totiJucatorii = self.getJucatori()
        for jucator in totiJucatorii:
            if nume == jucator.getNume() and prenume == jucator.getPrenume():
                ok = True
                jucator.setInaltime(inaltime)
        if ok == False:
            raise RepoError
        self.store(totiJucatorii)
        
    def getExtreme(self):
        '''
        iau extremele din jucatori
        '''
        jucatori = self.getJucatori()
        extreme = []
        for jucator in jucatori:
            if jucator.post=="Extrema":
                extreme.append(jucator)
                
        return extreme
    
    def getFundasi(self):
        '''
        iau fundasii din jucatori
        '''
        jucatori = self.getJucatori()
        fundasi = []
        for jucator in jucatori:
            if jucator.post=="Fundas":
                fundasi.append(jucator)
                
        return fundasi
    
    
    def getPivoti(self):
        '''
        iau pivotii din jucatori
        '''
        jucatori = self.getJucatori()
        pivoti = []
        for jucator in jucatori:
            if jucator.post=="Pivot":
                pivoti.append(jucator)
                
        return pivoti
        
    def catiJucatori(self):
        return len(self.getJucatori())    
    
    def existaJucatorul(self, nume, prenume):
        jucator = Jucator(nume,prenume,1,"Pivot")
        totiJucatorii=self.getJucatori()
        for jucatorr in totiJucatorii:
            if jucator == jucatorr:
                return True
        return False
        
    
def testAdaugaJucator():
    '''
    testez adaugarea de jucatori in repo
    '''
    repository = repositoryFisiere("testRepo.txt")       
    golescFisier("testRepo.txt")
    jucator1 = Jucator("bercea", "mondialu",123,"Pivot")
    jucator2= Jucator("marcel","necunoscutu",100,"Fundas")
    repository.adaugaJucator(jucator1)
    repository.adaugaJucator(jucator2)
    assert repository.catiJucatori() == 2
    
testAdaugaJucator()
        
        
        
        
        
        
            
        
        
        
        
        