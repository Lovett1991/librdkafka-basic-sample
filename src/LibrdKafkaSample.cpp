#include <iostream>
#include <librdkafka/rdkafkacpp.h>

using namespace std;

int main(int argc, char **argv)
{
    std::string brokers = "localhost";
    std::string errstr;

    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    RdKafka::Conf *tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

    if(conf -> set("metadata.broker.list", brokers, errstr)){
        cout << errstr << endl;
    }

    if (conf -> set("enable.partition.eof", "true", errstr)!= RdKafka::Conf::CONF_OK){
        cout << errstr << endl;
        return 1;
    }
    if(conf -> set("group.id", "foo", errstr)!= RdKafka::Conf::CONF_OK){
        cout << errstr << endl;
        return 1;
    }

    cout << "creating consumer" << endl;
    RdKafka::Consumer *consumer = RdKafka::Consumer::create(conf, errstr);
    cout << "creating topic" << endl;
    RdKafka::Topic *topic = RdKafka::Topic::create(consumer, "postgres.public.testtable", tconf, errstr);
    cout << "topic created" << endl;
    
    topic -> ~Topic();
    consumer -> ~Consumer();

    RdKafka::wait_destroyed(5000);

    return 0;
}