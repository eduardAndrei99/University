from domain.entitate import Jucator
from repository import repositoryFisiere, RepoError
from domain.validator import ValidatorJucator, ExceptieJucator
from utils.utils import golescFisier
import random

class Service():
    
    def __init__(self, validator, repository):
        '''
        :param validator
        :param repository
        service ul contine validator si repo
        '''
        self.validator = validator
        self.repository = repository


    def adaugaJucator(self, nume, prenume, inaltime, post):
        '''
        adaug un jucator
        '''
        jucator = Jucator(nume, prenume, inaltime, post)
        self.validator.validate(jucator)
        self.repository.adaugaJucator(jucator)
        return jucator
        
    def getJucatori(self):
        '''
        iau toti jucatorii din repository
        '''
        return self.repository.getJucatori()
    
    def modificaInaltime(self, nume, prenume, inaltime):
        return self.repository.modificaInaltime(nume, prenume, inaltime)
    
    def getFundasi(self):
        '''
        iau fundasii din jucatori
        '''
        fundasi = self.repository.getFundasi()
        fundasi = sorted(fundasi, key = lambda x: (len(x.getInaltime()), x.getInaltime()), reverse= True)
        return fundasi
    
    def getPivoti(self):
        '''
        iau pivotii din jucatori
        '''
        pivoti = self.repository.getPivoti()
        pivoti = sorted(pivoti, key = lambda x: (len(x.getInaltime()), x.getInaltime()), reverse = True)
        return pivoti
    
    def getExtreme(self):
        '''
        iau extremele din jucatori
        '''
        extreme = self.repository.getExtreme()
        extreme = sorted(extreme,key= lambda x: (len(x.getInaltime()), x.getInaltime()), reverse = True)
        return extreme
    
    def facEchipa(self,fundasi,pivoti,extreme):
        '''
        :param fundasi:
        :param pivoti:
        :param extreme:
        iau jucatorii cei mai inalti
        '''
        
        echipa = []
        echipa.append(fundasi[0])
        echipa.append(fundasi[1])
        echipa.append(extreme[0])
        echipa.append(extreme[1])
        echipa.append(pivoti[0])
        return echipa
    
    def existaJucatorul(self, nume,prenume):
        return self.repository.existaJucatorul(nume,prenume)
    
    
    def importaJucatori(self, numeFisier):
        
        try:
            fisier = open(numeFisier)
        except IOError:
            print("Nu i bine")
            return
        
        numar = 0
        posturi = ["Pivot","Extrema","Fundas"]
        linie = fisier.readline().strip()
        while linie != "":
            delimitator = linie.split(",")
            nume = delimitator[0]
            prenume = delimitator[1]
            inaltime = random.randint(1,200)
            post = posturi[random.randint(0,2)]
            if self.existaJucatorul(nume, prenume) == False:
                self.adaugaJucator(nume, prenume, inaltime, post)
                numar +=1
            linie = fisier.readline().strip()
        return numar
        
        
    
    
    
    
def testAdaugJucator():
    '''
    testez adaugarea unui jucator
    '''
    
    golescFisier("testService.txt")
    repository = repositoryFisiere("testService.txt")
    validator = ValidatorJucator()
    service = Service(validator, repository)
    nume = "eduard"
    prenume = "andrei"
    inaltime = 180
    post = "Pivot"
    try:
        jucator = service.adaugaJucator(nume, prenume, inaltime, post)
        assert jucator.getNume() == "eduard"
        assert jucator.getInaltime() == 180
    except ExceptieJucator as ex:
        assert False
    inaltime = -1
    try :
        jucator = service.adaugaJucator(nume,prenume,inaltime,post)
        assert False
    except ExceptieJucator:
        assert True
    golescFisier("testService.txt")

def testFacEchipa():
    '''
    testez o echipa
    '''
    golescFisier("testService.txt")
    repository = repositoryFisiere("testService.txt")
    validator = ValidatorJucator()
    service = Service(validator, repository)
    service.adaugaJucator("eduard", "andrei", 180, "Pivot")
    service.adaugaJucator("cristiano","ronaldo",100,"Pivot")
    service.adaugaJucator("ciprian","tatarusanu",30,"Pivot")
    service.adaugaJucator("leo","messi",100,"Extrema")
    service.adaugaJucator("mihai","ion",400,"Extrema")
    service.adaugaJucator("romeo","fantastik",103,"Extrema")
    service.adaugaJucator("guta","nikolae",4043,"Fundas")
    service.adaugaJucator("becali","gigi",30,"Fundas")
    service.adaugaJucator("borcea","nasu",1120,"Fundas")
    fundasi = service.getFundasi()
    extreme = service.getExtreme()
    pivoti = service.getPivoti()
    echipa = service.facEchipa(fundasi, pivoti, extreme)
    assert echipa[0].getInaltime() == "4043"
    assert echipa[1].getInaltime() == "1120"
    
def testModificaInaltime():
    '''
    testez modificarea inaltimii
    '''
    golescFisier("testService.txt")
    repository = repositoryFisiere("testService.txt")
    validator = ValidatorJucator()
    service = Service(validator, repository)
    service.adaugaJucator("eduard", "andrei", 180, "Pivot")
    service.adaugaJucator("cristiano","ronaldo",100,"Pivot")
    service.adaugaJucator("ciprian","tatarusanu",30,"Pivot")
    service.adaugaJucator("leo","messi",100,"Extrema")
    service.adaugaJucator("mihai","ion",400,"Extrema")
    service.adaugaJucator("romeo","fantastik",103,"Extrema")
    service.adaugaJucator("guta","nikolae",4043,"Fundas")
    service.adaugaJucator("becali","gigi",30,"Fundas")
    service.adaugaJucator("borcea","nasu",1120,"Fundas")
    nume = "becali"
    prenume = "gigi"
    inaltime = 200
    try:
        service.modificaInaltime(nume, prenume, inaltime)
        assert True
    except RepoError as ex:
        assert False
    nume = "mihaela"
    prenume="prenumeNume"
    inaltime = 69
    try:
        service.modificaInaltime(nume, prenume, inaltime)
        assert False
    except RepoError as ex:
        assert True


testAdaugJucator()    
testFacEchipa()
testModificaInaltime()
    
    
    
    
    
