import pytest
from .ServiceTestClient import ServiceTestClient
import os
from RobotRaconteur.Client import *

def test_properties(test_server_node_config):
    service_url = test_server_node_config.get_service_url("RobotRaconteurTestService")
    c = ServiceTestClient()
    c.ConnectService(service_url)
    try:
        c.TestProperties()
    finally:
        c.DisconnectService()

