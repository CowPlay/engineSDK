/*
 * CConfigReader.cpp
 *
 *  Created on: Aug 7, 2012
 *      Author: gregorytkach
 */

#include "CPlayerConfigReader.h"
#include "io/serialize/IAttributes.h"
#include "io/SharedFileSystem.h"

namespace irrgame
{
	namespace io
	{

		//! Default constructor
		CPlayerConfigReader::CPlayerConfigReader() :
				XMLReader(0), Entry(0)
		{

		}

		//! Destructor
		CPlayerConfigReader::~CPlayerConfigReader()
		{
		}

		void CPlayerConfigReader::read(const c8* file)
		{
			//TODO: implement
//			XMLReader = SharedFileSystem::getInstance().createXMLReader(file);
//
//			Entry = new SPlayerConfigEntry();
//
//			bool configRead = false;
//
//			do
//			{
//				switch (XMLReader->getNodeType())
//				{
//					case EXNT_ELEMENT:
//					{
//						core::stringc nodeName = XMLReader->getNodeName();
//
//						if (nodeName == XMLTagApplication)
//						{
//							parseApplication(XMLReader);
//						}
//
//						break;
//					}
//					case EXNT_ELEMENT_END:
//					{
//						core::stringc nodeName = XMLReader->getNodeName();
//
//						if (nodeName == XMLTagConfig)
//						{
//							configRead = true;
//							XMLReader->read();
//						}
//
//						break;
//					}
//					case EXNT_NONE:
//					case EXNT_TEXT:
//					case EXNT_COMMENT:
//					case EXNT_CDATA:
//					case EXNT_UNKNOWN:
//					{
//						break;
//					}
//					default:
//					{
//						// Not implemented
//						IRR_ASSERT(false);
//						break;
//					}
//				}
//			} while (!configRead && XMLReader->read());
//
//			if (XMLReader)
//			{
//				XMLReader->drop();
//			}
		}

		//! Parse <application/>
		void CPlayerConfigReader::parseApplication(IXMLReader* xml)
		{
			bool appRead = false;

			do
			{
				switch (xml->getNodeType())
				{
					case EXNT_ELEMENT:
					{
						core::stringc nodeName = xml->getNodeName();

						if (nodeName == XMLTagAttributes)
						{
							io::IAttributes* attr =
									SharedFileSystem::getInstance().createEmptyAttributes();

							attr->read(xml, true);

							if (attr->existsAttribute(XMLAttrAppFile))
							{
								Entry->AppFile = attr->getAttributeAsString(
										XMLAttrAppFile);
							}

							if (attr->existsAttribute(XMLAttrAppCreator))
							{
								Entry->AppCreator = attr->getAttributeAsString(
										XMLAttrAppCreator);
							}

							attr->drop();
						}

						break;
					}
					case EXNT_ELEMENT_END:
					{
						core::stringc nodeName = xml->getNodeName();

						if (nodeName == XMLTagApplication)
						{
							appRead = true;
							xml->read();
						}

						break;
					}
					case EXNT_NONE:
					case EXNT_TEXT:
					case EXNT_COMMENT:
					case EXNT_CDATA:
					case EXNT_UNKNOWN:
					default:
						break;
				}
			} while (!appRead && xml->read());

		}

		//! Gets enty which contains data from config
		SPlayerConfigEntry* CPlayerConfigReader::getEntry()
		{
			return Entry;
		}

		//! Internal funtcion. Please do not use.
		IPlayerConfigReader* createPlayerConfigReader()
		{
			return new CPlayerConfigReader();
		}

	}
}
