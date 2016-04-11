#ifndef PIFVIEWER_H
#define PIFVIEWER_H

#include "Singleton.h"

#include "Image.h"

class PIFViewer : public Singleton<PIFViewer>
{
	friend Singleton<PIFViewer>;

public:
	void Show (Image* image);
private:
	PIFViewer ();
	~PIFViewer ();
	PIFViewer (const PIFViewer&);
	PIFViewer& operator=(const PIFViewer&);
};

#endif