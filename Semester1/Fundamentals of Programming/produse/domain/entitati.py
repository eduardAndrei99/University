"""
entitatea produs
"""


class Produs():
    '''
    clasa produs ce contine id denumire pret
    '''
    def __init__(self, id, denumire, pret):
        '''
        :param id: id ul produsului
        :param denumire: denumirea
        :param pret: pretu;
        '''
        self.id = id
        self.denumire = denumire
        self.pret = pret

    
    def getId(self):
        '''
        get ul pentru id
        '''
        return self.id

    
    def getDenumire(self):
        '''
        get ul pentru denumire
        '''
        return self.denumire

    
    def getPret(self):
        '''
        get ul pentru pret
        '''
        return self.pret

def testProdus():
    '''
    testarea entitatii produs
    '''
    produs = Produs("1","milka","312")
    assert produs.getId() == "1"
    assert produs.getDenumire() == "milka"
    assert produs.getPret() == "312"
    

testProdus()