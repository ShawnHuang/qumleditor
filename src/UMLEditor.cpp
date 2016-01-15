#include "UMLEditor.h"
#include "View.h" 
#include "Canvas.h"
#include "Button.h"
#include "SelectButton.h"
#include "ClassBoxButton.h"
#include "UseCaseButton.h"
#include "AssLineButton.h"
#include "ComLineButton.h"
#include "GenLineButton.h"
#include <iostream>
#include <QButtonGroup>
#include <QMenuBar>
UMLEditor::UMLEditor(QWidget *parent) : QMainWindow(parent){
  canvas = new Canvas();
  view = new View();
  this->layout();
}
UMLEditor::~UMLEditor(){
  std::cout<<"UMLEditor delete"<<std::endl; 
  delete canvas;
  delete view;
  delete btnGroup;
  delete buttons[0];

  delete menubar;
  
  delete exit;
  delete group;
  delete ungroup;
  delete named;

  delete toolPanelLayout;
  delete mainLayout;
  delete toolPanel;
  delete mainPanel;
}

void UMLEditor::layout(){
  mainPanel = new QWidget;
  mainLayout = new QHBoxLayout;

  btnGroup = new QButtonGroup(this);
  btnGroup->setExclusive(true);

  SelectButton *btn = new SelectButton(canvas);
  ClassBoxButton *btn2 = new ClassBoxButton(canvas);
  btnGroup->addButton(btn);
  btnGroup->addButton(btn2);
  buttons.push_back(new SelectButton(canvas));
  buttons.push_back(new ClassBoxButton(canvas));
  buttons.push_back(new UseCaseButton(canvas));
  buttons.push_back(new AssLineButton(canvas));
  buttons.push_back(new GenLineButton(canvas));
  buttons.push_back(new ComLineButton(canvas));
  buttons[0]->pressed();

  for(std::vector<Button*>::size_type i = 0; i != buttons.size(); i++) {
    btnGroup->addButton(buttons[i]);
  }

  toolPanel = new QWidget;
  toolPanelLayout = new QGridLayout;
  toolPanelLayout->setAlignment(Qt::AlignTop);

  for(std::vector<QToolButton*>::size_type i = 0; i != buttons.size(); i++) {
    toolPanelLayout->addWidget(buttons[i], i, 0, Qt::AlignHCenter);
  }

  toolPanel->setLayout(toolPanelLayout);
  toolPanel->setMinimumWidth(100);

  menubar = new QMenuBar;
  file =  menubar->addMenu(tr("&File"));
  edit =  menubar->addMenu(tr("&Edit"));

  exit = new QAction(tr("Exit"), mainPanel);
  this->connect(exit, SIGNAL(triggered()), this, SLOT(close()));
  group = new QAction(tr("Group"), mainPanel);
  this->connect(group, SIGNAL(triggered()), canvas, SLOT(group()));
  ungroup = new QAction(tr("UnGroup"), mainPanel);
  this->connect(ungroup, SIGNAL(triggered()), canvas, SLOT(ungroup()));
  named = new QAction(tr("Change Object Name"), mainPanel);
  this->connect(named, SIGNAL(triggered()), canvas, SLOT(named()));

  file->addAction(exit);
  edit->addAction(group);
  edit->addAction(ungroup);
  edit->addAction(named);

  canvas->setSceneRect(QRectF(-200,-200,400,400));
  //view->setDragMode(QGraphicsView::RubberBandDrag);
  view->setScene(canvas);
  view->resize(400,400);

  mainLayout->addWidget(toolPanel,0);
  mainLayout->setAlignment(toolPanel,Qt::AlignTop);
  mainLayout->addWidget(view,1);
  mainLayout->setMenuBar(menubar);

  mainPanel->setLayout(mainLayout);
  setCentralWidget(mainPanel);
}
/* vim: set ft=cpp.qt : */
