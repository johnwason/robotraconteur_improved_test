import RobotRaconteur as RR
from RobotRaconteur.RobotRaconteurPythonUtil import PackMessageElement, UnpackMessageElement
from .ServiceTest2 import ServiceTest2_fill_teststruct3, ServiceTest2_verify_teststruct3

def test_servicetest2_types():
    node = RR.RobotRaconteurNode()
    node.Init()

    try:
        node.RegisterServiceTypesFromFiles(["com.robotraconteur.testing.TestService2","com.robotraconteur.testing.TestService1", 
                "com.robotraconteur.testing.TestService3","com.robotraconteur.testing.TestService5"])
        s1 = ServiceTest2_fill_teststruct3(node, 1000, None)
        s1_m = PackMessageElement(s1, 'com.robotraconteur.testing.TestService3.teststruct3', node=node)
        s1_m.UpdateData()
        s1_1 = UnpackMessageElement(s1_m, 'com.robotraconteur.testing.TestService3.teststruct3', node=node)
        ServiceTest2_verify_teststruct3(s1_1,1000)

    finally:
        node.Shutdown()