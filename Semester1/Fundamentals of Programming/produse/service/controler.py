'''
controll pentru produse
'''
from domain.entitati import Produs
from repository.repositoryFisierProdue import RepositoryProduse
from domain.validator import ExceptieProduse


class ServiceProduse():
    
    def __init__(self, repositoryProduse, validatorProduse):
        '''
        :param repositoryProduse: repository ul pentru produse
        :param validatorProduse:  validatorul
        '''
        self.repositoryProduse = repositoryProduse
        self.validatorProduse = validatorProduse

    
    def getProduse(self):
        '''
        functie ce ia produsele din fisier
        '''
        return self.repositoryProduse.getProduse()
    
    def adaugProdus(self,id, denumire, pret):
        '''
        :param id:
        :param denumire:
        :param pret:
        cei 3 parametri..
        validam din repo si validator si adaugam frumos
        '''
        produs = Produs(id,denumire, pret)
        self.validatorProduse.validate(produs)
        self.repositoryProduse.verific(produs)
        self.repositoryProduse.adaugProdus(produs)
        return produs
    
    def stergProduse(self, cifra):
        return self.repositoryProduse.stergProduse(cifra)
    
    def afisezCuFiltru(self,numeFiltru,numarFiltru):
        return self.repositoryProduse.afisezCuFiltru(numeFiltru, numarFiltru)
    
    
def testAdaugProdus():
    id = ""
    denumire = ""
    pret = ""
    ctr = ServiceProduse()
    try:
        ctr.adaugProdus(id, denumire, pret)  
        assert False
    except ExceptieProduse as ex:
        assert True
    

testAdaugProdus()  
    
    
    
    
    
    
    
    
    