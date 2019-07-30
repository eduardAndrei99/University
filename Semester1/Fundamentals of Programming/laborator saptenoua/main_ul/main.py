'''
Created on 5 dec. 2018

Planul este : UI -> Service -> Repository -> Validator 

@author: Edy
'''

"""
Validatoarele -> pentru persoana si eveniment :
"""

from UI.consola import consola
from domain.validator import persoanaValidator, evenimentValidator
from service.persoaneService import persoanaService
from repository.persoaneRepository import persoaneRepository
from repository.evenimenteRepository import evenimenteRepository
from repository.inscrieriRepository import inscrieriRepository
from service.evenimenteService import evenimentService
from service.inscrieriService import inscriereService
from repository.fisiereRepository import filePersoaneRepository, fileEvenimenteRepository, fileInscriereRepository

"""
Repository urile -> pentru persoane, eveniment si inscrieri ( care depind de un validator) 
"""

'''
PersoanaValidator = persoanaValidator()    
EvenimentValidator = evenimentValidator()

PersoanaRepository = persoaneRepository(PersoanaValidator)
EvenimentRepository = evenimenteRepository(EvenimentValidator)
InscriereRepository = inscrieriRepository()
'''


PersoanaRepository = filePersoaneRepository("persoaneIn.txt")
EvenimentRepository = fileEvenimenteRepository("evenimente.txt")
InscriereRepository = fileInscriereRepository("inscrieri.txt")



"""
Service urile -> pentru persoane, evenimente si inscrieri
"""

PersoanaService = persoanaService(PersoanaRepository)
EvenimentService = evenimentService(EvenimentRepository)
InscriereService = inscriereService(InscriereRepository)

""" 
Consola -> ce are serviceurile 
"""

Consola = consola(PersoanaService, EvenimentService, InscriereService)

Consola.showUi()





