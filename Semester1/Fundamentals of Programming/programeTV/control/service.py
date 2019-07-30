from repository.repository import RepositoryEmisiune
from utils.utils import stergFisier
from domain.validator import ValidatorEmisiune
class Service():
    
    def __init__(self, validator, repository):
        '''
        :param validator:
        :param repository:
        service ul are validator si repository
        '''
        self.validator = validator
        self.repository = repository

    
    def stergEmisiune(self, nume, tip):
        '''
        dau comanda de stergere in repo
        '''
        self.repository.stergEmisiune(nume, tip)
    
    def actualizezEmisiune(self, nume, tip, durata, descriere):
        self.repository.actualizezEmisiune(nume, tip,durata, descriere)
    
    def getEmisiuni(self):
        return self.repository.getEmisiuni()
    
    def facProgram(self):
        return self.repository.facProgram()
    
    def blochezProgram(self, tip):
        self.repository.blochezProgram(tip)
    
def testStergEmisiune():
    '''
    test stergerea unei emisiuni
    '''
    stergFisier("testService.txt")
    #fisierul este gol
    fisier = open("testService.txt","w")
    fisier.write("aaa,tip1,32,ad")
    fisier.close()
    repository = RepositoryEmisiune("testService.txt")
    assert repository.cateEmisiuni() == 1
    validator = ValidatorEmisiune()
    service = Service(validator, repository)
    service.stergEmisiune("aaa", "tip1")
    assert repository.cateEmisiuni() == 0
    

def testActualizezEmisiune():
    '''
    testez actulizarea unei emisiuni
    '''
    stergFisier("testService.txt")
    #fisierul este gol
    fisier = open("testService.txt","w")
    fisier.write("aaa,tip1,32,ad")
    fisier.close()
    repository = RepositoryEmisiune("testService.txt")
    validator = ValidatorEmisiune()
    service = Service(validator, repository)
    service.actualizezEmisiune("aaa", "tip1", 22, "ba")
    emisiuni = service.getEmisiuni()
    assert emisiuni[0].getDescriere() =="ba"
    assert int(emisiuni[0].getDurata()) == 22


testActualizezEmisiune()
testStergEmisiune()
    
