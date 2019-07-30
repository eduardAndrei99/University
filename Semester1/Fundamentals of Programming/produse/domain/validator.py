
from domain.entitati import Produs

class ExceptieProduse(Exception):
    
    def __init__(self, erori):
        self.erori = erori
    
    def getErori(self):
        return self.erori


class ValidatorProduse:
    
    def validate(self, produs):
        erori = []
        if produs.getId() == "":
            erori.append("Id ul nu poate fi gol")
        if produs.getDenumire() == "":
            erori.append("Denumirea nu poate fi goala")
        if produs.getPret() == "":
            erori.append("Pretul nu poate fi gol")
        if (len(erori))>0:
            raise ExceptieProduse(erori)


def testValidare():
    validator = ValidatorProduse()
    produs = Produs("","","32")
    try:
        validator.validate(produs)
        assert False
    except ExceptieProduse as ex:
        assert len(ex.getErori()) == 2

testValidare()

        

