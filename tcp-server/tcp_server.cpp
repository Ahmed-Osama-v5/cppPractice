#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char **argv)
{

  try
  {
    // Any program that uses asio need to have at least one io_service object
    boost::asio::io_service io_service;

    // acceptor object needs to be created to listen for new connections
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 2100));

    // creates a socket
    tcp::socket socket(io_service);

    // wait and listen
    acceptor.accept(socket);
    std::cout << "Client Connected" << std::endl;

    std::array<uint8_t, 7> receivedMessage;
    boost::system::error_code ignored_error;

    bool connectionRequestSent = false;

    bool connectAgain = false;

    for (;;)
    {
      // // creates a socket
      // tcp::socket socket(io_service);

      // // wait and listen
      // acceptor.accept(socket);
      // std::cout << "Client Connected" << std::endl;

      // std::array<uint8_t, 7> receivedMessage;
      // boost::system::error_code ignored_error;

      // socket.receive(boost::asio::buffer(receivedMessage));
      // std::cout << "Data received from client " << std::endl;
      // for (auto element : receivedMessage)
      //   std::cout << std::hex << +element << " ";
      // std::cout << std::endl;

      // socket.receive(boost::asio::buffer(receivedMessage));
      // std::cout << "Data received from client " << std::endl;
      // for (auto element : receivedMessage)
      //   std::cout << std::hex << +element << " ";
      // std::cout << std::endl;

      // socket.receive(boost::asio::buffer(receivedMessage));
      // std::cout << "Data received from client " << std::endl;
      // for (auto element : receivedMessage)
      //   std::cout << std::hex << +element << " ";
      // std::cout << std::endl;

      // socket.receive(boost::asio::buffer(receivedMessage));
      // std::cout << "Data received from client " << std::endl;
      // for (auto element : receivedMessage)
      //   std::cout << std::hex << +element << " ";
      // std::cout << std::endl;

      if (connectAgain)
      {
        std::cout << "Waiting for connection" << std::endl;
        acceptor.accept(socket);
        std::cout << "Client Connected" << std::endl;
        connectAgain = false;
      }

      boost::system::error_code error;

      socket.read_some(boost::asio::buffer(receivedMessage), error);

      if (error == boost::asio::error::eof)
      {
        boost::system::error_code closeError;
        std::cout << "Connection closed cleanly by peer" << std::endl;

        if (socket.is_open())
        {
          std::cout << "closing connection" << std::endl;
          socket.close();
          connectAgain = true;
        }
        else
        {
          std::cout << "socket is not open" << std::endl;
        }

        // acceptor.close(closeError);
        // if (closeError)
          // std::cout << "Error closing connection" << std::endl;
        continue; // Connection closed cleanly by peer.
      }
      else if (error)
        throw boost::system::system_error(error); // Some other error.

      for (auto element : receivedMessage)
        std::cout << std::hex << +element << " ";
      std::cout << std::endl;

      if(!connectionRequestSent){
        if (argc > 2)
        {
          std::cout << "Too many arguments\n";
          return 0;
        }

        if (argc == 2)
        {
          std::string connectionOption = argv[1];

          if (connectionOption == "-c" || connectionOption == "-C")
          {
            std::cout << "Connection request\n";
            // Connect request
            std::vector<uint8_t> internetGatewayConnectionRequestMessage{0x50, 0x41, 0x53, 0x53};
            internetGatewayConnectionRequestMessage.push_back(2);
            internetGatewayConnectionRequestMessage.push_back(0x01);
            internetGatewayConnectionRequestMessage.push_back(0x01);

            std::cout << "Sending request" << std::endl;
            socket.send(boost::asio::buffer(internetGatewayConnectionRequestMessage));

            socket.receive(boost::asio::buffer(receivedMessage));
            std::cout << "Data received from client " << std::endl;
            for (auto element : receivedMessage)
              std::cout << std::hex << +element << " ";
            std::cout << std::endl;
          }
          else if (connectionOption == "-d" || connectionOption == "-D")
          {
            std::cout << "Disonnection request\n";
            // Disonnect request
            std::vector<uint8_t> internetGatewayDisconnectionRequestMessage{0x50, 0x41, 0x53, 0x53};
            internetGatewayDisconnectionRequestMessage.push_back(2);
            internetGatewayDisconnectionRequestMessage.push_back(0x01);
            internetGatewayDisconnectionRequestMessage.push_back(0x02);

            std::cout << "Sending request" << std::endl;
            socket.send(boost::asio::buffer(internetGatewayDisconnectionRequestMessage));

            socket.receive(boost::asio::buffer(receivedMessage));
            std::cout << "Data received from client " << std::endl;
            for (auto element : receivedMessage)
              std::cout << std::hex << +element << " ";
            std::cout << std::endl;
          }
          else
          {
            std::cout << "Invalid arguments\nOptions are:\n-C for Connection\n-D for Disconnection\n";
          }
        }
        connectionRequestSent = true;
      }
    }
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}