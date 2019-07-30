'''
Created on 20 feb. 2019

@author: Edy
'''
from domain.validator import ValidatorTraducere
from ui.consola import Consola
from controller.service import Service
from repository.repository import Repository


repository = Repository("traduceri.txt")
validator = ValidatorTraducere()
service = Service(validator, repository)
consola = Consola(service)

consola.showUi()