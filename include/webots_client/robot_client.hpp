// Copyright (c) 2021 ICHIRO ITS
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef WEBOT_CLIENT__ROBOT_CLIENT_HPP_
#define WEBOT_CLIENT__ROBOT_CLIENT_HPP_

#include <musen/musen.hpp>

#include <string>
#include <memory>

namespace webots_client
{

class RobotClient : public musen::BaseClient
{
public:
  explicit RobotClient(
    const std::string & host, const int & port,
    std::shared_ptr<musen::TcpSocket> tcp_socket = std::make_shared<musen::TcpSocket>());

  bool connect();

  std::shared_ptr<SensorMeasurements> receive();
  int send(const ActuatorRequests & data);
};

}  // namespace webots_client

#endif  // WEBOT_CLIENT__ROBOT_CLIENT_HPP_
