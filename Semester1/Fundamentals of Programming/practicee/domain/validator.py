
from domain.entitati import Student


class ExceptieStudent(Exception):
    def __init__(self,erori):
        self.erori = erori
    
    def getErori(self):
        return self.erori
        
class ValidatorStudent:
    
    def validate(self, student):
        
        erori = []
        if student.getId() == "":
            erori.append("id ul nu poate fi gol")
        if student.getNume() == "":
            erori.append("numele nu poate fi gol")
        if student.getAdresa() == "":
            erori.append("adresa nu poate fi goala")
        if len(erori) > 0:
            raise ExceptieStudent(erori)


        
def testValidator():
    validator = ValidatorStudent()
    student = Student("","","yeas")
    try:
        validator.validate(student)
        assert False
    except ExceptieStudent as ex:
        assert len(ex.getErori()) == 2
        
testValidator()
        

