class Student():
    
    def __init__(self, id, nume, adresa):
        self.id = id
        self.nume = nume
        self.adresa = adresa

    
    def getId(self):
        return self.id

    
    def getNume(self):
        return self.nume

    
    def getAdresa(self):
        return self.adresa
    
    

def testStudent():
    student = Student("1","mihai","cluj")
    assert student.getId() == "1"
    assert student.getNume() == "mihai"
    assert student.getAdresa() == "cluj"        


