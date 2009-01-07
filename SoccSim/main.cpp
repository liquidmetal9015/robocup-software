#include "Vision.hpp"
#include "Viewer.hpp"
#include "Physics/Env.hpp"
#include "Config.hpp"

#include <QApplication>

#include <NxPhysics.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Env* env = new Env();
	env->start();

	Config cfg("../config/sample.xml", env);

        Vision vision(env);
        vision.start();

	Viewer win(env);
	win.setVisible(true);

        int ret = app.exec();

	//cleanup
	delete env;
        vision.terminate();
        vision.wait();

	return ret;
}
