/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
First_pluginAudioProcessorEditor::First_pluginAudioProcessorEditor (First_pluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(0.0f, 10.0f, 0.1f);
    mGainSlider.setValue(5.0f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);

    addAndMakeVisible(gainLabel);
    gainLabel.setText("Gain", juce::dontSendNotification);
    gainLabel.attachToComponent(&mGainSlider, false);

    mVolSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mVolSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mVolSlider.setRange(0.0f, 1.0f, 0.01f);
    mVolSlider.setValue(0.5f);
    mVolSlider.addListener(this);
    addAndMakeVisible(mVolSlider);

    addAndMakeVisible(volumeLabel);
    volumeLabel.setText("Volume", juce::dontSendNotification);
    volumeLabel.attachToComponent(&mVolSlider, false);

    setSize (400, 300);
}

First_pluginAudioProcessorEditor::~First_pluginAudioProcessorEditor()
{
}

//==============================================================================
void First_pluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void First_pluginAudioProcessorEditor::resized()
{
    mGainSlider.setBounds(getWidth() / 2 - 20, getHeight() /2 - 75, 100, 150);

    mVolSlider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 75, 100, 150);
}

void First_pluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &mGainSlider)
        audioProcessor.mGain = mGainSlider.getValue();
    else if (slider == &mVolSlider)
        audioProcessor.mVol = mVolSlider.getValue();
}
