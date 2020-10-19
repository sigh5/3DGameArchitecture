#include "ICleanUp.h"
#include "ISetPosition.h"
#include "IUpdate.h"
#include <vector>

class RenderingObject;

class Renderer :public ICleanUp, public ISetPosition,public IUpdate
{
private:
	std::vector< RenderingObject*> objects;
	float _camera_a;
	float _camera_b;
	float _camera_c;


public:

	static Renderer* instance() {

		static Renderer instance;

		return &instance;
	}
	
public:
	void init();
	
	glm::mat4 getMatrixTranslatePosition(glm::mat4 Model, RenderingObject *obj);
	glm::mat4 getCameraPosition()const; //camera 시점 이동
	void addObject(RenderingObject *_object);
	void draw();
	void renderup();
	void renderdown();

public:
	virtual void shutDown()override;
	virtual void setXYZ(float x, float y, float z)override; 
	virtual void Update(IUpdate *iupdate)override;


private :
	void renderer(RenderingObject* _object);  //ㅇ젠 드로우함수에서 다쓸려고 
};