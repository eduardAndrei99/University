
from domain.entitati import Student
from domain.validator import ValidatorStudent,ExceptieStudent
from repository.inMemorieRepository import inMemorieRepository,\
    RepositoryExceptie

class ServiceStudent():
    
    def __init__(self, repositoryStudent, validatorStudent):
        self.repositoryStudent = repositoryStudent
        self.validatorStudent = validatorStudent

    
    def adaugareStudent(self, id, nume, adresa):
        student = Student(id,nume,adresa)
        self.validatorStudent.validate(student)
        self.repositoryStudent.adaugStudent(student)
        return student
    
    def getAllStudent(self):
        return self.repositoryStudent.getAllStudent()
        
        
def testCreareStudent():
    rep = inMemorieRepository()
    val = ValidatorStudent()
    service = ServiceStudent(rep,val)
    st = service.adaugareStudent("1","mihai","cluj")
    totiStd = service.getAllStudent()
    assert len(totiStd) == 1
    try:
        st = service.adaugareStudent("1","vasi","adr")
        assert False
    except RepositoryExceptie:
        assert True
        
testCreareStudent()       
        
        
        
        