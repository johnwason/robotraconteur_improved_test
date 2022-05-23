import pytest
from .ServiceTestClient import ServiceTestClient
from .service_test_util import TestServerNodeConfig
import os

def test_properties(test_server_node_config):
    service_url = test_server_node_config.get_service_url("RobotRaconteurTestService")
    c = ServiceTestClient()
    c.ConnectService(service_url)
    try:
        c.TestProperties()
    finally:
        c.DisconnectService()


@pytest.fixture
def test_server_node_config():
    robdef_path = os.path.abspath(os.path.dirname(os.path.abspath(__file__)) + "/../../robdef")
    os.environ["ROBOTRACONTEUR_ROBDEF_PATH"] = robdef_path
    return TestServerNodeConfig("unit_test_service_python")
