#include "optionchooser.h"

OptionChooser::OptionChooser(QMap<QString, double> opt)
{
    //This copies the opt list to options so we have the right size list.
    options = opt;

    //Create Dialog
    main = new QDialog();
    main->resize(300,300);
    QGridLayout* back = new QGridLayout(main);
    optList = new QListWidget();
    QPushButton* ok = new QPushButton("OK");
    QLabel* label = new QLabel("Options: ");
    back->cellRect(3, 1);
    back->addWidget(label, 1, 1);
    back->addWidget(optList, 2, 1);
    back->addWidget(ok, 3, 1);

    connect(ok, &QPushButton::clicked, [=]() {
        main->hide();
        emit boxClosed(options);
    });

    //Adds the items from the QMap to the dialog list
    QMap<QString, double>::iterator i;
    for(i = options.begin(); i != options.end(); ++i) {
        QListWidgetItem* item = new QListWidgetItem(i.key());
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        optList->addItem(item);
    }

    connect(optList, &QListWidget::itemChanged, [=](QListWidgetItem* item) {getNumber(item);});
}

void OptionChooser::getNumber(QListWidgetItem *item) {
    //This updates the map with the preference
    QString name = item->text();
    if(item->checkState() == Qt::Checked) {
        if(name.contains("Enter")) {
            double value(QInputDialog::getDouble(NULL, name, "Insert new value: "));
            options.insert(name, value);
        } else {
            options.insert(name, 1);
        }
    } else {
        options.insert(name, 0);
    }

}

//Literally just displays the window
void OptionChooser::show () {
    main->show();
}
