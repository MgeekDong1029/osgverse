#ifndef MANA_HIERARCHY_HPP
#define MANA_HIERARCHY_HPP

#include <osg/Node>
#include <osg/NodeVisitor>
#include <ui/ImGui.h>
#include <ui/ImGuiComponents.h>

namespace osgVerse
{ struct CommandData; }

class Hierarchy : public osgVerse::ImGuiComponentBase
{
public:
    Hierarchy(osg::Camera* camera, osg::MatrixTransform* mt);
    bool handleCommand(osgVerse::CommandData* cmd);
    virtual bool show(osgVerse::ImGuiManager* mgr, osgVerse::ImGuiContentHandler* content);

protected:
    osg::observer_ptr<osg::Camera> _camera;
    osg::observer_ptr<osg::MatrixTransform> _sceneRoot;

    osg::ref_ptr<osgVerse::Window> _treeWindow;
    osg::ref_ptr<osgVerse::MenuBar> _treeMenuBar;
    osg::ref_ptr<osgVerse::TreeView> _treeView;
    osgVerse::TreeView::TreeData _camTreeData, _sceneTreeData;
};

#endif