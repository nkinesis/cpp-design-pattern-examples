#include "StudyInterface.h"
#include "StudyAbstract.h"
#include "StudyFactory.h"
#include "StudyAbstractFactory.h"
#include "StudySingleton.h"
#include "StudyIterator.h"
#include "StudyCommand.h"
#include "StudyFlyweight.h"

/* Pattern studies: all examples
* Examples by Gabriel C. Ullmann (2022), adapted from: 
* Refactoring Guru (2022). https://refactoring.guru/design-patterns/abstract-factory.
* KUCHANA (2004). Software Architecture Design Patterns in Java.
*/

int main() {

    printf("============================= \n");
    printf("Example: interface pattern \n");
    printf("============================= \n");
    /*
    Why is this useful?
    ===================
    By using an interface, you can create a sort of class "skeleton": a set of methos that must be implemented
    by any child class. In other words, anyone who inherits from your class must implemented the methods described 
    in its body. In this case, all kinds of employees must implement a "getSalary" method.
    */
    Developer d1("Gabriel");
    d1.setExtraHours(5);
    printf("Salary Gabriel = %f\n", d1.getSalary());

    Salesperson s1("Jean", 1);
    s1.setMonthlySales(200);
    printf("Salary Jean = %f\n", s1.getSalary());

    Salesperson s2("Marie", 3);
    s2.setMonthlySales(100.00);
    printf("Salary Marie = %f\n", s2.getSalary());

    printf("============================= \n");
    printf("Example: abstract class pattern \n");
    printf("============================= \n");

    /*
    Why is this useful?
    ===================
    By using an interface, you can just create a class "skeleton" that can be implemented by other classes.
    With an abstract class, you can create the "skeleton" plus some functionality that can be inherited by
    the implementing classes. In this case, Dog inherits methods written in the Animal class, and is also "obligated"
    to implement other "skeleton" methods from Animal.
    */
    Dog a;
    a.beGoodBoy();
    a.makeNoise();
    a.move(1);
    a.move(0);

    printf("============================= \n");
    printf("Example: factory pattern \n");
    printf("============================= \n");

    /*
    Why is this useful?
    ===================
    Before creating the object, the factory can do other checks for you (e.g: fetch config from database)
    If there was no factory, you would have to do all the checks yourself and then pass the necessary data
    via constructor to the object you want to create
    */
    LoggerFactory lf;
    Logger* logger = lf.getLogger();
    logger->log("hello factory\n");

    printf("============================= \n");
    printf("Example: abstract factory pattern \n");
    printf("============================= \n");

    /*
    Why is this useful?
    ===================
    When you call a luxury vehicle factory, you know all vehicles provided by it will be luxury.
    There is no need to check if you are using the right object. This is good especially when
    the purpose of the object is not so well defined in its name (e.g: it is not called "luxury")
    */
    RegularVehicleFactory rvf;
    Car* c = rvf.getCar();
    std::cout << "Vehicle is luxury vehicle? ";
    std::cout << c->getLuxury();
    std::cout << "\n";
    LuxuryVehicleFactory lvf;
    c = lvf.getCar();
    std::cout << "Vehicle is luxury vehicle? ";
    std::cout << c->getLuxury();
    std::cout << "\n";

    printf("============================= \n");
    printf("Example: Singleton pattern \n");
    printf("============================= \n");

    /*
    Why is this useful?
    ===================
    You use it when you want to make sure a given class will have no more than 1 instance. I used Engine as an example:
    you usually wouldn't want to have 2 engine instances, since this would mean 2 video/audio renderers, 2 game loops.
    In the context of an engine, you would never use 2 of it at the same time.
    */
    std::cout << "If working properly, should print the same instance name twice.\n";
    Engine* engine = Engine::getInstance("Main instance\n");
    Engine* engine2 = Engine::getInstance("Another one\n");
    std::cout << engine->getName();
    std::cout << engine2->getName();
    engine->runGameLoop();

    printf("============================= \n");
    printf("Example: iterator pattern \n");
    printf("============================= \n");

    /*
    Why is this useful?
    ===================
    When you iterate using a loop, you have to take care of everything: how to access the data you want, how to
    go forwards, backwards, etc. An iterator "hides" all that work from you and replaces that by method calls with
    "friendly" names. Wanna go forward? Call "next()". It's simple as that. No need to increase an index or something.
    The Iterator class does that all behind the scenes for you. In this simple example, I created an iterator to go
    back and forth in an integer vector.
     */
    VectorIterator vi({ 3, 5, 7, 5, 2, 5, 3 });

    //print in regular order
    while (vi.hasNext()) {
        std::cout << vi.next() << std::endl;
    }

    //print only even values
    vi.first();
    while (vi.hasNext()) {
        if (vi.getCurrentValue() % 2 == 0) {
            std::cout << vi.getCurrentValue() << " is an even number " << std::endl;
        }
        vi.next();
    }

    //print in reverse order
    vi.last();
    while (vi.getCurrentIndex() > 0) {
        std::cout << vi.prev() << std::endl;
    }
    std::cout << vi.getCurrentValue() << std::endl;

    printf("============================= \n");
    printf("Example: command pattern \n");
    printf("============================= \n");

    /*
    Why is this useful?
    ===================
    - Imagine, for example, we need to also pass the command move to asteroids
    in the scenario, or to other spaceships.
    - For this reason is useful to have the command as an object (and not a string, for example).
    - Also, a layer in the middle allows us to define what to do before and after certain commands.
    - This layer can do all this things before passing the command to the receiver, which may do additional things.
    */
    Spaceship* enterprise = new Spaceship("Enterprise");
    Invoker* invk = new Invoker();
    invk->setOnStart(new MoveCommand(enterprise, 1));
    invk->setOnFinish(new ShootCommand(enterprise));
    invk->execute();

    printf("============================= \n");
    printf("Example: flyweight pattern \n");
    printf("============================= \n");
    /*
    Why is this useful?
    ===================
    Imagine you want to create a bunch of objects in a game. In this example, I used meteors.
    Each meteor has unique characteristics, that change from meteor to meteor. For example, 
    their speed and spin direction. These are extrinsic characteristics. The intrinsic ones, however,
    are the same for everyone. In our game, all meteors have the same texture, 3d model and particle system.
    So why query the asset database every time to get that info? Just create an object that fetches this info once,
    then reuse it ad infinitum.
    */
    FlyweightMeteorFactory fmf;
    FlyweightMeteor* fm = fmf.getFlyweight();
    vector<Meteor> meteorShower;

    for (unsigned int i = 0; i < 5; i++) {
        meteorShower.push_back(Meteor(i, true, fm));
    }
    for (unsigned int i = 0; i < 5; i++) {
        printf("Meteor speed = %i\n", meteorShower[i].getSpeed());
    }
    std::cout << "Number of meteors created: " << meteorShower.size();

    return 0;
}