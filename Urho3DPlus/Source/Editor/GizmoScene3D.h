#pragma once




#include <Urho3D/Core/Object.h>
#include "EPScene3D.h"
#include <Urho3D/Math/Ray.h>



namespace Urho3D
{

	class Node;
	class StaticModel;
	class Scene;
	class EditorData;
	class EditorSelection;
	class EPScene3D;

	class GizmoAxis : public Object
	{
		URHO3D_OBJECT(GizmoAxis, Object);
	public:
		/// Construct.
		GizmoAxis(Context* context);
		/// Destruct.
		virtual ~GizmoAxis();

		void Update(Ray cameraRay, float scale, bool drag,const Vector3& camPos);

		void Moved();

		Ray axisRay;
		bool selected;
		bool lastSelected;
		float t;
		float d;
		float lastT;
		float lastD;
	};


	class GizmoScene3D : public Object
	{
		URHO3D_OBJECT(GizmoScene3D, Object);
	public:
		/// Construct.
		GizmoScene3D(Context* context, EPScene3D* epScene3D);
		/// Destruct.
		virtual ~GizmoScene3D();
		void CreateGizmo();
		void HideGizmo();
		void ShowGizmo();

		void UpdateGizmo();

		void PositionGizmo();
		void ResizeGizmo();

		void CalculateGizmoAxes();

		void GizmoMoved();
		void UseGizmo();
		bool IsGizmoSelected();
	protected:
		EditorData*			editorData_;
		EditorSelection*	editorSelection_;

		SharedPtr<Node> gizmoNode;
		SharedPtr<StaticModel> gizmo;
		EditMode lastGizmoMode;

		SharedPtr<GizmoAxis> gizmoAxisX;
		SharedPtr<GizmoAxis> gizmoAxisY;
		SharedPtr<GizmoAxis> gizmoAxisZ;
		EPScene3D* epScene3D_;
		// For undo
// 		bool previousGizmoDrag;
// 		bool needGizmoUndo;
// 		Array<Transform> oldGizmoTransforms;
	};
}