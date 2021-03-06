/*
 * Software License Agreement (Apache License)
 *
 * Copyright (c) 2016 Shaun Edwards
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>
#include <ros/time.h>
#include <QCoreApplication>
#include <QTimer>
#include <boost/thread/thread.hpp>
#include <ros/console.h>

void qtWorker(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.exec();
}

int main(int argc, char **argv)
{
  boost::thread* thr = new boost::thread(&qtWorker, argc, argv);
  ros::Time::init();
  while(NULL == QCoreApplication::instance())
  {
    ROS_INFO_STREAM_THROTTLE(0.1, "Waiting for QCore application to start");
  }
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
